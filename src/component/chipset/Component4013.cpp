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
	std::vector<nts::Pin *> tab = _pins;
	int truthTable[5][6] = {
			{ 1, 0, 0, 0, 0, 1 },
			{ 1, 1, 0, 0, 1, 0 },
			{ -1, -1, 1, 0, 0, 1 },
			{ -1, -1, 0, 1, 1, 0 },
			{ -1, -1, 1, 1, 1, 1 }
	};

	for (int c = 0; c != 14; c++) {
		if (c == 0 || c == 1) {
			_pins[c] = new Pin([tab, truthTable, c]() {
				int sequence[4] = {tab[2]->compute(), tab[3]->compute(), tab[4]->compute(), tab[5]->compute()};
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
				return tab[c]->getState();
			});
		} else if (c == 11 || c == 12) {
			_pins[c] = new Pin([tab, truthTable, c]() {
                int sequence[4] = {tab[7]->compute(), tab[8]->compute(), tab[9]->compute(), tab[10]->compute()};
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
                return tab[c]->getState();
			});
		} else {
			_pins[c] = new Pin([tab, c]()->Tristate
			{
			    class Pin *pin = tab[c]->getLink();

			    if (!pin)
			        return (tab[c]->getState());
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
