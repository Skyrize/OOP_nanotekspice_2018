/*
 ** EPITECH PROJECT, 2019
 ** OOP_nanotekspice_2018
 ** File description: Created on: 30 janv. 2019
 ** Component4514.cpp
 */

#include "Component4514.hpp"

namespace nts {

Component4514::Component4514(const std::string& name)
: Component(name)
{
	_pins = std::vector<Pin *>(24);

	for (int i = 0; i != 24; i++)
		_pins.push_back(new Pin(nullptr));
}

Component4514::~Component4514()
{
	// TODO Auto-generated destructor stub
}

} /* namespace nts */
