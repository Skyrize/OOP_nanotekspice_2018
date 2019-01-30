/*
 ** EPITECH PROJECT, 2019
 ** OOP_nanotekspice_2018
 ** File description: Created on: 29 janv. 2019
 ** NanoError.cpp
 */

#include "NanoError.hpp"

nts::NanoError::NanoError(const std::string& message)
: _message(message)
{
}

nts::NanoError::~NanoError()
{
	// TODO Auto-generated destructor stub
}

nts::CircuitFileError::CircuitFileError(const std::string& message)
: NanoError(message)
{
}

nts::ComponentTypeError::ComponentTypeError(const std::string& message)
: NanoError(message)
{
}

nts::ComponentNameError::ComponentNameError(const std::string& message)
: NanoError(message)
{
}

nts::UnexistingPinError::UnexistingPinError(const std::string& message)
: NanoError(message)
{
}

nts::RedefinedComponentError::RedefinedComponentError(const std::string& message)
: NanoError(message)
{
}

nts::UnlinkedOutputError::UnlinkedOutputError(const std::string& message)
: NanoError(message)
{
}

nts::UnprovidedInputError::UnprovidedInputError(const std::string& message)
: NanoError(message)
{
}

nts::UnknowInputError::UnknowInputError(const std::string& message)
: NanoError(message)
{
}

nts::MissingChipsetSectionError::MissingChipsetSectionError(
		const std::string& message)
: NanoError(message)
{
}

nts::MissingLinksSectionError::MissingLinksSectionError(const std::string& message)
: NanoError(message)
{
}

nts::UsageError::UsageError(const std::string& message)
: NanoError(message)
{
}
