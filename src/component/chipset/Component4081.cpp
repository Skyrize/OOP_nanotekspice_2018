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
<<<<<<< HEAD
    Pin *pin = nullptr;
    Tristate (*input)() = []()->Tristate {};
    Tristate (*output)() = []()->Tristate {};
    Tristate (*def)() = []()->Tristate {};

	for (int i = 0; i <= 14; ++i) {
        pin = new Pin();
        if (i == 3 || i == 4 || i == 10 || i == 11) {

        } else {
            output = []()->Tristate {

            }
            pin->setCompute([pin]()->Tristate {

            });
            // _pins[i - 1]
        }
    }
=======
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
>>>>>>> b36423e1ce9fda4fdb9426f2f59e4c32e50bc284
}

Component4081::~Component4081()
{
	// TODO Auto-generated destructor stub
}

} /* namespace nts */
