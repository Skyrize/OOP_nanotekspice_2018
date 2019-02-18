/*
 ** EPITECH PROJECT, 2019
 ** OOP_nanotekspice_2018
 ** File description: Created on: 30 janv. 2019
 ** Component4514.cpp
 */

#include "Component4514.hpp"

namespace nts {

Component4514::Component4514(const std::string& name)
		: Component(name)
{
	_pins = std::vector<Pin *>(24);
	int truthTable[16][4] = {
			{ 0, 0, 0, 0 },
			{ 0, 0, 0, 1 },
			{ 0, 0, 1, 0 },
			{ 0, 0, 1, 1 },
			{ 0, 1, 0, 0 },
			{ 0, 1, 0, 1 },
			{ 0, 1, 1, 0 },
			{ 0, 1, 1, 1 },
			{ 1, 0, 0, 0 },
			{ 1, 0, 0, 1 },
			{ 1, 0, 1, 0 },
			{ 1, 0, 1, 1 },
			{ 1, 1, 0, 0 },
			{ 1, 1, 0, 1 },
			{ 1, 1, 1, 0 },
			{ 1, 1, 1, 1 },
		};

	for (int i = 0; i != 24; i++) {
		if ((i >= 3 && i <= 10) || (i >= 12 && i <= 19)) {
			_pins[i] = new Pin([&, truthTable, i]()->Tristate
			{
				int sequence[6] = {this->getPin(21+1)->compute(), this->getPin(20+1)->compute(), this->getPin(2+1)->compute(), this->getPin(1+1)->compute(), this->getPin(22+1)->compute(), this->getPin(1)->compute()};
				bool comparaisonSucceed = true;
				int i = 0;

				if (sequence[5] == 1 || sequence[6] == 0)
					return Tristate::FALSE;
				for (; i != 16; i++, comparaisonSucceed = true) {
					for (int j = 0; j != 4; j++) {
						if (sequence[j] == Tristate::UNDEFINED)
							return Tristate::UNDEFINED;
						else if (sequence[j] != truthTable[i][j])
							comparaisonSucceed = false;
					}
					if (comparaisonSucceed == true)
						return (Tristate::TRUE);
				}
				return Tristate::UNDEFINED;

			});
		} else {
			_pins[i] = new Pin([&, i]()->Tristate
			{
				class Pin *pin = this->getPin(i+1)->getLink();

				if (!pin)
				return (this->getPin(i+1)->getState());
				return (pin->compute());
			});
		}
	}
}

Component4514::~Component4514()
{
	// TODO Auto-generated destructor stub
}

} /* namespace nts */
