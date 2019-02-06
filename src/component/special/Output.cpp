/*
 ** EPITECH PROJECT, 2019
 ** OOP_nanotekspice_2018
 ** File description: Created on: 30 janv. 2019
 ** Output.cpp
 */

#include "Output.hpp"
#include "Pin.hpp"

namespace nts {

Output::Output(const std::string &name)
: Component(name)
{
	_pins = std::vector<Pin *>(1);
    class Pin *self = this->_pins[0];

	_pins[0] = new Pin([self]() -> Tristate {
        return (self->getLink()->compute());
    });
}

Output::~Output()
{
	// TODO Auto-generated destructor stub
}

} /* namespace nts */
