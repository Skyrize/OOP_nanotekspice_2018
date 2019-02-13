/*
 ** EPITECH PROJECT, 2019
 ** OOP_nanotekspice_2018
 ** File description: Created on: 30 janv. 2019
 ** Clock.cpp
 */

#include "Clock.hpp"

namespace nts {

Clock::Clock(const std::string &name, Tristate value)
: Input(name, value)
{
    _pins = std::vector<Pin *>(1);

    _pins[0] = new Pin([&]() -> Tristate {
        return this->getPin(1)->getState();
    }, value);
}

Clock::~Clock()
{
	// TODO Auto-generated destructor stub
}

} /* namespace nts */
