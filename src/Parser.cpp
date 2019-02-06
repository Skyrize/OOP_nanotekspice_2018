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

	if (!this->ntsFile)
		throw CircuitFileError("Unable to open \'" + fileName + "\' file");
}

Parser::~Parser()
{
}

void Parser::skipCommentsAndEmptyLines(std::string &line)
{
	while (std::getline(ntsFile, line)) {
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

void Parser::parseLink(std::string &line, Circuit *circuit)
{
	std::replace(line.begin(), line.end(), '\t', ' ');
	std::vector<std::string> lineContent = getLineContent(line, ' ');

	if (lineContent.size() != 2)
		throw CircuitFileError(
				"Linkage error. Usage: \'componentX:pinX \'componentY:pinY\'");

	std::vector<std::string> linkContent01 = getLineContent(lineContent[0],
			':');
	std::vector<std::string> linkContent02 = getLineContent(lineContent[1],
			':');
	IComponent *link01 = components[linkContent01[0]];
	IComponent *link02 = components[linkContent02[0]];

	if (!link01 || !link02)
		throw ComponentNameError();

	size_t pin1 = getComponentPin(lineContent[0]);
	size_t pin2 = getComponentPin(lineContent[1]);
	link01->setLink(pin1, *link02, pin2);
}

void Parser::performLinksParsing(Circuit *circuit)
{
	std::string line;

	while (std::getline(ntsFile, line)) {
		std::replace(line.begin(), line.end(), '\t', ' ');
		if (line.empty() || line.at(0) == '#') {
			continue;
		}

		parseLink(line, circuit);
	}
}

void Parser::parseComponent(std::string &line, Circuit *circuit)
{
	std::replace(line.begin(), line.end(), '\t', ' ');
	std::vector<std::string> lineContent = getLineContent(line, ' ');

	if (lineContent.size() == 1)
		throw CircuitFileError(
				"Component \'" + lineContent[0]
						+ "\' must be provided with a name.");

	std::unique_ptr<IComponent> newComponent(
			std::move(
					Factory::createComponent(lineContent[0], lineContent[1])));
	IComponent *elem = newComponent.get();

	if (lineContent[0] == "input") {
		circuit->pushInput(newComponent);
	} else if (lineContent[0] == "output") {
		circuit->pushOutput(newComponent);
	} else {
		circuit->pushComponent(newComponent);
	}
	if (this->components[lineContent[1]])
		throw RedefinedComponentError();

	if (lineContent[1].find('(') == std::string::npos) {
		this->components[lineContent[1]] = elem;
	} else {
		this->components[lineContent[1].substr(0, lineContent[1].find('('))] =
				elem;
	}
}

void Parser::performChipsetParsing(Circuit *circuit)
{
	std::string line;

	while (line != ".links:") {
		if (line.empty() || line.at(0) == '#') {

			if (!getline(ntsFile, line))
				throw MissingLinksSectionError();
			continue;

		} else {
			parseComponent(line, circuit);
		}

		if (!getline(ntsFile, line))
			throw MissingLinksSectionError();

	}
}

void Parser::parseArgument(std::string argument)
{
	std::vector<std::string> lineContent;
	lineContent = getLineContent(argument, '=');
	if (!components[lineContent[0]])
		throw UnknowInputError();
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
			if (tmp->getPin(1)->isLinked() == false)
				throw UnlinkedOutputError();
		}
	}
}

Circuit* Parser::processParsing(int nbArgs, char **arguments)
{
	Circuit *circuit = new Circuit();
	std::string line;

	skipCommentsAndEmptyLines(line);
	if (line.empty() == true)
		throw CircuitFileError(
				"Warning: file provided is empty of comment-only");
	if (line != ".chipsets:") {
		throw MissingChipsetSectionError(
				"Expected \".chipsets:\" section but got \"" + line + "\"");
	} else {
		performChipsetParsing(circuit);
		performLinksParsing(circuit);
		performArgumentsParsing(nbArgs, arguments);
		verifyInputInitialisation();
		verifyOutputLinkage();
	}
	return circuit;
}

}
