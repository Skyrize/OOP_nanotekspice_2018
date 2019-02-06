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

nts::Component::Component(const std::string& name)
: _name(name)
{
}

class Pin *nts::Component::getPin(const size_t& pin)
{
		return this->_pins[pin];
}
}
