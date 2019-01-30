/*
 ** EPITECH PROJECT, 2019
 ** OOP_nanotekspice_2018
 ** File description: Created on: 30 janv. 2019
 ** Component.cpp
 */

#include "Component.hpp"

namespace nts {

Component::~Component()
{
	// TODO Auto-generated destructor stub
}

nts::Tristate Component::compute(size_t pin)
{
	(void)pin;
	return nts::Tristate::TRUE;
}

void Component::setLink(size_t pin, nts::IComponent& other, size_t otherPin)
{
	(void)pin;
	(void)other;
	(void)otherPin;
}

void Component::dump() const
{
}

class Pin* Component::getPin(size_t pin) const
{
		(void)pin;
		return nullptr;
}

} /* namespace nts */

nts::Component::Component(const std::string& name)
: name(name)
{
}
