/*
 ** EPITECH PROJECT, 2019
 ** OOP_nanotekspice_2018
 ** File description: Created on: 29 janv. 2019
 ** NanoError.cpp
 */

#include "NanoError.hpp"

NanoError::NanoError(const std::string& message)
: _message(message)
{
}

NanoError::~NanoError()
{
	// TODO Auto-generated destructor stub
}

CircuitFileError::CircuitFileError(const std::string& message)
: NanoError(message)
{
}

ComponentTypeError::ComponentTypeError(const std::string& message)
: NanoError(message)
{
}

ComponentNameError::ComponentNameError(const std::string& message)
: NanoError(message)
{
}

UnexistingPinError::UnexistingPinError(const std::string& message)
: NanoError(message)
{
}

RedefinedComponentError::RedefinedComponentError(const std::string& message)
: NanoError(message)
{
}

UnlinkedOutputError::UnlinkedOutputError(const std::string& message)
: NanoError(message)
{
}

UnprovidedInputError::UnprovidedInputError(const std::string& message)
: NanoError(message)
{
}

UnknowInputError::UnknowInputError(const std::string& message)
: NanoError(message)
{
}

MissingChipsetSectionError::MissingChipsetSectionError(
		const std::string& message)
: NanoError(message)
{
}

MissingLinksSectionError::MissingLinksSectionError(const std::string& message)
: NanoError(message)
{
}
