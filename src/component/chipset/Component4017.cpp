/*
 ** EPITECH PROJECT, 2019
 ** OOP_nanotekspice_2018
 ** File description: Created on: 30 janv. 2019
 ** Component4017.cpp
 */

#include "Component4017.hpp"

namespace nts {

Component4017::Component4017(const std::string& name)
: Component(name)
{
	_pins = std::vector<Pin *>(15);

	for (int i = 0; i != 15; i++)
		_pins[i] = new Pin([&, i](){std::cout << "4017 not done" << std::endl;
		return this->getPin(i + 1)->getState();});
}

Component4017::~Component4017()
{
	// TODO Auto-generated destructor stub
}

} /* namespace nts */
