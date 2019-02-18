/*
 ** EPITECH PROJECT, 2019
 ** OOP_nanotekspice_2018
 ** File description: Created on: 30 janv. 2019
 ** Parser.cpp
 */

#include <sstream>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <memory>
#include <string>
#include "Input.hpp"
#include "Output.hpp"
#include "Parser.hpp"
#include "Factory.hpp"
#include "Pin.hpp"
#include "NanoError.hpp"

namespace nts {

Parser::Parser(const std::string& fileName)
{
	this->ntsFile.open(fileName.c_str(), std::ifstream::in);

	if (this->ntsFile.good() == false)
		throw CircuitFileError("Unable to open \'" + fileName + "\' file");
}

Parser::~Parser()
{
}

void Parser::skipCommentsAndEmptyLines(std::string &line)
{
	while (std::getline(ntsFile, line)) {
		line.erase(line.begin(), std::find_if(line.begin(), line.end(), std::bind1st(std::not_equal_to<char>(), ' ')));
		if (line.empty() || line.at(0) == '#') {
			continue;
		} else
			break;
	}
}

std::vector<std::string> Parser::getLineContent(std::string &line,
		const char &delimiter)
{
	std::istringstream iss(line);
	std::vector<std::string> tokens;
	std::string token;

	while (std::getline(iss, token, delimiter)) {
		if (token.empty() == false)
			tokens.push_back(token);
	}
	return tokens;
}

size_t Parser::getComponentPin(const std::string &component)
{
	std::istringstream iss(component);
	std::vector<std::string> tokens;
	std::string token;
	int value = 0;

	while (std::getline(iss, token, ':')) {
		if (token.empty() == false)
			tokens.push_back(token);
	}
	if (tokens.size() != 2)
		throw CircuitFileError(
				"Linkage error. Usage: \'componentX:pinX \'componentY:pinY\'");
	try {
		value = std::stoi(tokens[1]);
	} catch (std::exception &e) {
		throw CircuitFileError(
				"Pin error: value ins't a number for pin \'" + tokens[0]
						+ "\'");
	}
	return value;
}

void Parser::parseLink(std::string comp1, std::string comp2, Circuit *circuit)
{
	std::vector<std::string> linkContent01 = getLineContent(comp1, ':');
	std::vector<std::string> linkContent02 = getLineContent(comp2, ':');
	IComponent *link01 = components[linkContent01[0]];
	IComponent *link02 = components[linkContent02[0]];

	if (!link01 || !link02)
		throw ComponentNameError();

	size_t pin1 = getComponentPin(comp1);
	size_t pin2 = getComponentPin(comp2);
	link01->setLink(pin1, *link02, pin2);
}

void Parser::performLinksParsing(Circuit *circuit, std::vector<std::vector<std::string>> &content)
{
	if (content.size() == 0)
		throw MissingLinksSectionError();
	content.erase(content.begin());
	while (content.size() > 0) {
		if (content[0].size() != 2)
			throw CircuitFileError();
		parseLink(content[0][0], content[0][1], circuit);
		content.erase(content.begin());
	}
}

void Parser::parseComponent(std::string type, std::string name, Circuit *circuit)
{
	std::unique_ptr<IComponent> newComponent(
			std::move(Factory::createComponent(type, name)));
	IComponent *elem = newComponent.get();

	if (dynamic_cast<Input *>(elem)) {
		circuit->pushInput(newComponent);
	} else if (dynamic_cast<Output *>(elem)) {
		circuit->pushOutput(newComponent);
	} else {
		circuit->pushComponent(newComponent);
	}
	if (this->components[name])
		throw RedefinedComponentError();

	if (name.find('(') == std::string::npos) {
		this->components[name] = elem;
	} else {
		this->components[name.substr(0, name.find('('))] = elem;
	}
}

void Parser::performChipsetParsing(Circuit *circuit, std::vector<std::vector<std::string>> &content)
{
	if (content[0][0] != ".chipsets:")
		throw MissingChipsetSectionError();
	content.erase(content.begin());
	while (content.size() > 0 && content[0][0] != ".links:") {
		if (content[0].size() != 2)
			throw CircuitFileError();
		parseComponent(content[0][0], content[0][1], circuit);
		content.erase(content.begin());
	}
}

void Parser::parseArgument(std::string argument)
{
	std::vector<std::string> lineContent;
	lineContent = getLineContent(argument, '=');
	if (!components[lineContent[0]])
		throw UnknowInputError("Input \'" + lineContent[0] + "\' is unknow.");
	if (std::stoi(lineContent[1]) == Tristate::TRUE) {
		components[lineContent[0]]->getPin(1)->setState(Tristate::TRUE);
	} else if (std::stoi(lineContent[1]) == Tristate::FALSE) {
		components[lineContent[0]]->getPin(1)->setState(Tristate::FALSE);
	} else {
		throw UnknowInputError(
				"Tu pensais vraiment pouvoir init un input avec autre chose que 0 ou 1 ? tu me prends pour un amateur ?");
	}

}

void Parser::performArgumentsParsing(int nbArgs, char** arguments)
{

	for (int i = 2; i < nbArgs; i++) {
		parseArgument(std::string(arguments[i]));
	}
}

void Parser::verifyInputInitialisation()
{
	Input *tmp = nullptr;

	for (auto &e : components) {
		tmp = dynamic_cast<Input *>(e.second);
		if (tmp) {
			if (tmp->getPin(1)->getState() == Tristate::UNDEFINED)
				throw UnprovidedInputError("Input \'" + tmp->getName() + "\' value was not provided on the command line.");
		}
	}
}

void Parser::verifyOutputLinkage()
{
	Output *tmp = nullptr;

	for (auto &e : components) {
		tmp = dynamic_cast<Output *>(e.second);
		if (tmp) {
			if (tmp->getPin(1)->getLink() == nullptr)
				throw UnlinkedOutputError("Output \'" + tmp->getName() + "\' isn't linked.");
		}
	}
}

std::vector<std::string> Parser::ParseLine(std::string line)
{
	if (line.empty())
		return std::vector<std::string> ();
	std::replace(line.begin(), line.end(), '\t', ' ');

	if (line.find('#') != std::string::npos) {
		line.insert(line.find('#'), " ");
		line.insert(line.find('#') + 1, " ");
	}
	std::vector<std::string> lineContent = getLineContent(line, ' ');

	if (line.find('#') != std::string::npos) {
		auto finder2 = std::find(lineContent.begin(), lineContent.end(), "#");
		lineContent.erase(finder2, lineContent.end());
		
	}
	return lineContent;
}

Circuit* Parser::processParsing(int nbArgs, char **arguments)
{
	Circuit *circuit = new Circuit();
	std::string line;
	std::vector<std::vector<std::string>> content;

	while (std::getline(ntsFile, line)) {
		std::vector<std::string> tmp = ParseLine(line);
		if (tmp.empty())
			continue;
		content.push_back(tmp);
	}
	//content.erase(content.begin());
	// for (auto e : content) {
	// 	for (auto a : e)
	// 		std::cout << a << " | ";
	// 	std::cout << std::endl;
	// }
		
	if (content.empty())
		throw CircuitFileError("Warning: file provided is empty of comment-only");
	performChipsetParsing(circuit, content);
	performLinksParsing(circuit, content);

	performArgumentsParsing(nbArgs, arguments);
	verifyInputInitialisation();
	verifyOutputLinkage();
	this->ntsFile.close();
	return circuit;
}

}
