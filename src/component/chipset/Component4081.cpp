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
}

Component4081::~Component4081()
{
	// TODO Auto-generated destructor stub
}

} /* namespace nts */
