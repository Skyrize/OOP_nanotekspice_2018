/*
 ** EPITECH PROJECT, 2019
 ** OOP_nanotekspice_2018
 ** File description: Created on: 30 janv. 2019
 ** Parser.cpp
 */

#include <map>
#include <algorithm>
#include <sstream>
#include <iterator>
#include "Parser.hpp"

namespace nts {

using ComponentPusher = void (Circuit::*)(IComponent *component);

static const std::map<std::string, ComponentPusher> pushersPointers = {
		{"input", &Circuit::pushInput},
		{"output", &Circuit::pushOutput},
};

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

std::vector<std::string> Parser::getLineContent(std::string &line)
{
	std::replace(line.begin(), line.end(), '\t', ' ');
	std::replace(line.begin(), line.end(), '(', ' ');
	std::replace(line.begin(), line.end(), ')', ' ');

	std::istringstream iss(line);
	std::vector<std::string> tokens;
	std::string token;

	while (std::getline(iss, token, ' '))
	{
		if (token.empty() == false)
			tokens.push_back(token);
	}
	return tokens;
}

void Parser::performLinksParsing(Circuit *circuit)
{
}

void Parser::parseComponent(std::string &line, Circuit *circuit)
{
	std::vector<std::string> lineContent = getLineContent(line);

	if (lineContent.size() == 1)
		throw CircuitFileError("Component \'" + lineContent[0] + "\' must be provided with a name.");

	std::cout << "--------TODO: " << "load component by type in Parser::parseComponent" << std::endl;
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
	performLinksParsing(circuit);
}

Circuit* Parser::processParsing()
{
	Circuit *circuit = new Circuit();
	std::string line;

	skipCommentsAndEmptyLines(line);
	if (line.empty() == true)
		throw CircuitFileError("Warning: file provided is empty of comment-only");
	if (line != ".chipsets:") {
		throw MissingChipsetSectionError("Expected \".chipsets:\" section but got \"" + line + "\"");
	} else {
		performChipsetParsing(circuit);
	}
	return circuit;
}

}
