/*
 ** EPITECH PROJECT, 2019
 ** OOP_nanotekspice_2018
 ** File description: Created on: 30 janv. 2019
 ** Component4094.cpp
 */

#include "Component4094.hpp"

namespace nts {

Component4094::Component4094(const std::string& name)
: Component(name)
{
	_pins = std::vector<Pin *>(16);

	for (int i = 0; i != 16; i++)
		_pins.push_back(new Pin(nullptr));
}

Component4094::~Component4094()
{
	// TODO Auto-generated destructor stub
}

} /* namespace nts */
