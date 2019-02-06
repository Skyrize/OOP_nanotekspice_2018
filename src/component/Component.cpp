/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description: Created on: 30 janv. 2019
** Component.cpp
*/

#include "Component.hpp"
#include "Pin.hpp"
#include "NanoError.hpp"

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
	Pin *pin1 = this->getPin(pin);
	Pin *pin2 = other.getPin(otherPin);

	pin1->setLink(pin2);
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
		if (this->_pins.size() <= pin - 1)
			throw UnexistingPinError("In component \'" + this->_name + "\', requested pin " + std::to_string(pin) + " is out of bound.");
		return this->_pins[pin - 1];
}
}
