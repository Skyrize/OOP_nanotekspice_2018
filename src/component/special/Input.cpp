/*
 ** EPITECH PROJECT, 2019
 ** OOP_nanotekspice_2018
 ** File description: Created on: 30 janv. 2019
 ** Input.cpp
 */

#include "Input.hpp"
#include "Pin.hpp"

namespace nts {

Input::Input(const std::string &name, Tristate value)
: Component(name)
{
	_pins[0] = new Pin(nullptr, value);
}

Input::~Input()
{
	// TODO Auto-generated destructor stub
}

} /* namespace nts */
