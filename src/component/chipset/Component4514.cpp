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
    int arr[16] = {11, 9, 10, 8, 7, 6, 5, 4, 18, 17, 20, 19, 14, 13, 16, 15};

	for (int i = 0; i != 24; i++) {
		if ((i >= 3 && i <= 10) || (i >= 12 && i <= 19)) {
			_pins[i] = new Pin([&, truthTable, arr, i]()->Tristate
			{
				int sequence[6] = {this->getPin(21+1)->compute(),
                                    this->getPin(20+1)->compute(),
                                    this->getPin(2+1)->compute(),
                                    this->getPin(1+1)->compute(),
                                    this->getPin(22+1)->compute(),
                                    this->getPin(1)->compute()
                                };
				bool comparaisonSucceed = true;
                int x = 0;
                int on = 0;

				if (sequence[4] == 1)
					return Tristate::FALSE;
                else if (sequence[5] == 0)
                    return Tristate::UNDEFINED;
				for (int j = 0; j < 16; j++) {
                    for (x = 0; x < 4; x++)
                        if (sequence[x] == Tristate::UNDEFINED)
                            return Tristate::UNDEFINED;
                        else if (sequence[x] != truthTable[j][x])
                            break;
                    if (x == 4) {
                        on = j;
                        break;
                    }
                }
                for (int j = 0; j < 16; j++)
                    this->getPin(arr[j])->setState(FALSE);
                this->getPin(arr[on])->setState(TRUE);
				return this->getPin(i + 1)->getState();
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
