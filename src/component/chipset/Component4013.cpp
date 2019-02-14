/*
 ** EPITECH PROJECT, 2019
 ** OOP_nanotekspice_2018
 ** File description: Created on: 30 janv. 2019
 ** Component4013.cpp
 */

#include "Component4013.hpp"

namespace nts {

Component4013::Component4013(const std::string& name)
		: Component(name)
{
	_pins = std::vector<Pin *>(14);
	int truthTable[5][6] = {
			{ 1, 0, 0, 0, 0, 1 },
			{ 1, 1, 0, 0, 1, 0 },
			{ -1, -1, 1, 0, 0, 1 },
			{ -1, -1, 0, 1, 1, 0 },
			{ -1, -1, 1, 1, 1, 1 }
	};

	for (int c = 0; c != 14; c++) {
		if (c == 0 || c == 1) {
			_pins[c] = new Pin([&, truthTable, c]() {
				int sequence[4] = {this->getPin(2 + 1)->compute(), this->getPin(3 + 1)->compute(), this->getPin(4 + 1)->compute(), this->getPin(5 + 1)->compute()};
				bool comparaisonSucceed = true;
				bool hasUndefined = false;
				int i = 0;

				for (; i != 5; i++, comparaisonSucceed = true, hasUndefined = false) {

					for (int j = 0; j != 4; j++) {
						if (truthTable[i][j] != -1)
							continue;
						if (sequence[j] == Tristate::UNDEFINED)
							hasUndefined = true;
						else if (sequence[j] != truthTable[i][j])
							comparaisonSucceed = false;
					}

					if (comparaisonSucceed == true) {
						if (hasUndefined == true)
							return (Tristate::UNDEFINED);
						else
							return (Tristate(truthTable[i][4 + c]));
					}
				}
				return this->getPin(c + 1)->getState();
			});
		} else if (c == 11 || c == 12) {
			_pins[c] = new Pin([&, truthTable, c]() {
                int sequence[4] = {this->getPin(7+1)->compute(), this->getPin(8+1)->compute(), this->getPin(9+1)->compute(), this->getPin(1+10)->compute()};
                bool comparaisonSucceed = true;
                bool hasUndefined = false;
                int i = 0;
                for (; i != 5; i++, comparaisonSucceed = true, hasUndefined = false) {
                    for (int j = 0; j != 4; j++) {
                        if (truthTable[i][j] != -1)
                            continue;
                        if (sequence[j] == Tristate::UNDEFINED)
                            hasUndefined = true;
                        else if (sequence[j] != truthTable[i][j])
                            comparaisonSucceed = false;
                    }
                    if (comparaisonSucceed == true) {
                        if (hasUndefined == true)
                            return (Tristate::UNDEFINED);
                        else
                            return (Tristate(truthTable[i][c - 8]));
                    }
                }
                return this->getPin(c+1)->getState();
			});
		} else {
			_pins[c] = new Pin([&, c]()->Tristate
			{
			    class Pin *pin = this->getPin(c + 1)->getLink();

			    if (!pin)
			        return (this->getPin(c + 1)->getState());
			    return (pin->compute());
			});
		}
	}
}

Component4013::~Component4013()
{
	// TODO Auto-generated destructor stub
}

} /* namespace nts */
