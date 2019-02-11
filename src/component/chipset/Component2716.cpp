/*
 ** EPITECH PROJECT, 2019
 ** OOP_nanotekspice_2018
 ** File description: Created on: 30 janv. 2019
 ** Component2716.cpp
 */

#include "Component2716.hpp"

namespace nts {

Component2716::Component2716(const std::string& name, const std::string &fileName)
: Component(name)
{
	_pins = std::vector<Pin *>(24);

	for (int i = 0; i != 24; i++)
		_pins[i] = new Pin(nullptr);

}

Component2716::~Component2716()
{
	// TODO Auto-generated destructor stub
}

} /* namespace nts */

nts::Component2716::Component2716(const std::string& name)
: Component(name)
{
}
