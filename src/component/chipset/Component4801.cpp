/*
 ** EPITECH PROJECT, 2019
 ** OOP_nanotekspice_2018
 ** File description: Created on: 30 janv. 2019
 ** Component4801.cpp
 */

#include "Component4801.hpp"

namespace nts {

Component4801::Component4801(const std::string& name)
: Component(name)
{
	_pins = std::vector<Pin *>(24);

	for (int i = 0; i != 24; i++)
		_pins[i] = new Pin([&, i](){std::cout << "4801 not done" << std::endl;
		return this->getPin(i + 1)->getState();});
}

Component4801::~Component4801()
{
	// TODO Auto-generated destructor stub
}

} /* namespace nts */
