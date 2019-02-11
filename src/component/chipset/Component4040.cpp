/*
 ** EPITECH PROJECT, 2019
 ** OOP_nanotekspice_2018
 ** File description: Created on: 30 janv. 2019
 ** Component4040.cpp
 */

#include "Component4040.hpp"

namespace nts {

Component4040::Component4040(const std::string& name)
: Component(name)
{
	_pins = std::vector<Pin *>(16);

	for (int i = 0; i != 16; i++)
		_pins.push_back(new Pin(nullptr));
}

Component4040::~Component4040()
{
	// TODO Auto-generated destructor stub
}

} /* namespace nts */
