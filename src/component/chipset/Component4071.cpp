/*
 ** EPITECH PROJECT, 2019
 ** OOP_nanotekspice_2018
 ** File description: Created on: 30 janv. 2019
 ** Component4071.cpp
 */

#include "Component4071.hpp"

namespace nts {

Component4071::Component4071(const std::string& name)
: Component(name)
{
	_pins = std::vector<Pin *>(13);

	for (int i = 0; i != 13; i++)
		_pins.push_back(new Pin(nullptr));
}

Component4071::~Component4071()
{
	// TODO Auto-generated destructor stub
}

} /* namespace nts */
