/*
 ** EPITECH PROJECT, 2019
 ** OOP_nanotekspice_2018
 ** File description: Created on: 30 janv. 2019
 ** Component4030.cpp
 */

#include "Component4030.hpp"

namespace nts {

Component4030::Component4030(const std::string& name)
: Component(name)
{
	_pins = std::vector<Pin *>(14);

	for (int i = 0; i != 14; i++)
		_pins.push_back(new Pin(nullptr));
}

Component4030::~Component4030()
{
	// TODO Auto-generated destructor stub
}

} /* namespace nts */
