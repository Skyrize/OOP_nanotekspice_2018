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
	_pins = std::vector<Pin *>(14);

	for (int i = 1; i != 15; i++) {
        if (i == 3 || i == 4 || i == 10 || i == 11) {
            _pins[i - 1] = new Pin([&, i]()->Tristate
            {
                Tristate state1;
                Tristate state2;
            
                if (i == 3 || i == 10) {
                    state1 = this->getPin(i - 1)->compute();
                    state2 = this->getPin(i - 2)->compute();
                } else {
                    state1 = this->getPin(i + 1)->compute();
                    state2 = this->getPin(i + 2)->compute();
                }
                return Gates::OR(state1, state2);
            });
        } else {
            _pins[i - 1] = new Pin([&, i]()->Tristate
            {
                class Pin *pin = this->getPin(i)->getLink();

                if (!pin)
                    return (this->getPin(i)->getState());
                return (pin->compute());
            });
        }
    }
}

Component4071::~Component4071()
{
	// TODO Auto-generated destructor stub
}

} /* namespace nts */
