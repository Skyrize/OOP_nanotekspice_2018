/*
 ** EPITECH PROJECT, 2019
 ** OOP_nanotekspice_2018
 ** File description: Created on: 30 janv. 2019
 ** Component4001.cpp
 */

#include "Component4001.hpp"

namespace nts {

Component4001::Component4001(const std::string& name)
		: Component(name)
{
	_pins = std::vector<Pin *>(14);
	std::vector<nts::Pin *> tab = _pins;

	for (int i = 0; i != 14; i++) {
		if (i == 2 || i == 10) {
			_pins[i] = new Pin([&, i]()->Tristate
			{
				Tristate state1;
				Tristate state2;

				state1 = this->getPin(i - 1)->compute();
				state2 = this->getPin(i - 2)->compute();
				return Gates::NOR(state1, state2);
			});
		} else if (i == 3 || i == 9) {
			_pins[i] = new Pin([&, i]()->Tristate
			{
				Tristate state1;
				Tristate state2;

				state1 = this->getPin(i + 1)->compute();
				state2 = this->getPin(i + 2)->compute();
				return Gates::NOR(state1, state2);
			});
		} else {
            _pins[i] = new Pin([&, i]()->Tristate
            {
                class Pin *pin = this->getPin(i)->getLink();

                if (!pin)
                    return (this->getPin(i)->getState());
                return (pin->compute());
            });
        }
	}
}

Component4001::~Component4001()
{
}

} /* namespace nts */
