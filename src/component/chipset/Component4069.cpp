/*
 ** EPITECH PROJECT, 2019
 ** OOP_nanotekspice_2018
 ** File description: Created on: 30 janv. 2019
 ** Component4069.cpp
 */

#include "Component4069.hpp"

namespace nts {

Component4069::Component4069(const std::string& name)
		: Component(name)
{
	_pins = std::vector<Pin *>(14);

	for (int i = 0; i != 14; i++) {
		if (i == 1 || i == 3 || i == 5) {
			_pins[i] = new Pin([&, i]()
			{
				Tristate state = this->getPin(i)->compute();

				if (state == Tristate::TRUE)
				return Tristate::FALSE;
				else if (state == Tristate::FALSE)
				return Tristate::TRUE;
				return Tristate::UNDEFINED;
			});
		} else if (i == 11 || i == 9 || i == 7) {
			_pins[i] = new Pin([&, i]()
			{
				Tristate state = this->getPin(i + 2)->compute();

				if (state == Tristate::TRUE)
				return Tristate::FALSE;
				else if (state == Tristate::FALSE)
				return Tristate::TRUE;
				return Tristate::UNDEFINED;
			});
		} else {
			_pins[i] = new Pin([&, i]()->Tristate
			{
				class Pin *pin = this->getPin(i+1)->getLink();

				if (!pin) {
					return (this->getPin(i + 1)->getState());
				}
				return (pin->compute());
			});
		}
	}
}

Component4069::~Component4069()
{
	// TODO Auto-generated destructor stub
}

} /* namespace nts */
