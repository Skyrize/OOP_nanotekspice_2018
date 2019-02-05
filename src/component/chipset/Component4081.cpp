/*
 ** EPITECH PROJECT, 2019
 ** OOP_nanotekspice_2018
 ** File description: Created on: 30 janv. 2019
 ** Component4081.cpp
 */

#include "Component4081.hpp"

namespace nts {

Component4081::Component4081(const std::string& name)
: Component(name)
{
	//todo do the real thing; this is for debug;
	this->pins.push_back(new Pin());
	this->pins.push_back(new Pin());
	this->pins.push_back(new Pin());
	this->pins.push_back(new Pin());
	this->pins.push_back(new Pin());
	this->pins.push_back(new Pin());
	this->pins.push_back(new Pin());
	this->pins.push_back(new Pin());
	this->pins.push_back(new Pin());
}

Component4081::~Component4081()
{
	// TODO Auto-generated destructor stub
}

} /* namespace nts */
