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
	return _pins[pin - 1]->compute();
}

void Component::setLink(size_t pin, nts::IComponent& other, size_t otherPin)
{
	Pin *pin1 = this->getPin(pin);
	Pin *pin2 = other.getPin(otherPin);

	pin1->setLink(pin2);
	pin2->setLink(pin1);
}

void Component::dump() const
{
    size_t it = 1;

    std::cout << "Component " << _name << ":" << std::endl;
    for (auto &i: _pins)
        std::cout << "Pin " << it++ << " = " << i->getState() << std::endl;
}

nts::Component::Component(const std::string& name)
: _name(name)
{
}

class Pin *nts::Component::getPin(const size_t& pin)
{
		if (this->_pins.size() <= pin - 1 || pin - 1 < 0)
			throw UnexistingPinError("In component \'" + this->_name + "\', requested pin " + std::to_string(pin) + " is out of bound.");
		return this->_pins[pin - 1];
}
}
