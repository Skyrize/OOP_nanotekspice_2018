/*
 ** EPITECH PROJECT, 2019
 ** OOP_nanotekspice_2018
 ** File description: Created on: 30 janv. 2019
 ** Component4011.cpp
 */

#include "Component4011.hpp"

namespace nts {

Component4011::Component4011(const std::string& name)
: Component(name)
{
	_pins = std::vector<Pin *>(14);

	for (int i = 0; i != 14; i++)
		_pins.push_back(new Pin(nullptr));
}

Component4011::~Component4011()
{
	// TODO Auto-generated destructor stub
}

} /* namespace nts */
