/*
 ** EPITECH PROJECT, 2019
 ** OOP_nanotekspice_2018
 ** File description: Created on: 30 janv. 2019
 ** Component4094.cpp
 */

#include "Component4094.hpp"

namespace nts {

Component4094::Component4094(const std::string& name)
		: Component(name)
{
	_pins = std::vector<Pin *>(16);

	int truthTable[6][4] = {
			{ 1, 0, -2, -2 },
			{ 0, 0, -2, -2 },
			{ 1, 1, 0, -2 },
			{ 1, 1, 1, 0 },
			{ 1, 1, 1, 1 },
			{ 0, 1, 1, 1 } };

	for (int c = 0; c != 16; c++) {
		if (c == 3) {
			_pins[c] = new Pin(
							[&, truthTable, c]() {
								int sequence[4] = {this->getPin(1)->compute(), this->getPin(15)->compute(), this->getPin(2)->compute(), this->getPin(3)->compute()};
								bool comparaisonSucceed = true;
								bool hasUndefined = false;
								int i = 0;

								for (; i != 6; i++, comparaisonSucceed = true, hasUndefined = false) {

									for (int j = 0; j != 4; j++) {
										if (truthTable[i][j] != -1)
										continue;
										if (sequence[j] == Tristate::UNDEFINED)
										hasUndefined = true;
										else if (sequence[j] != truthTable[i][j])
										comparaisonSucceed = false;
									}

									if (comparaisonSucceed == true) {
										if (hasUndefined == true || i == 0 || i == 1)
										return (Tristate::UNDEFINED);
										else {
											if (i == 3) {
												return (Tristate::FALSE);
											} else if (i == 4) {
												return (Tristate::TRUE);
											} else {
												return (this->getPin(c+1)->getState());
											}
										}
									}
								}
								return this->getPin(c+1)->getState();
							});
		} else if (c == 4 || c == 5 || c == 6) {
			_pins[c] =
					new Pin(
							[&, truthTable, c]() {
								int sequence[4] = {this->getPin(1)->compute(), this->getPin(15)->compute(), this->getPin(2)->compute(), this->getPin(3)->compute()};
								bool comparaisonSucceed = true;
								bool hasUndefined = false;
								int i = 0;

								for (; i != 6; i++, comparaisonSucceed = true, hasUndefined = false) {

									for (int j = 0; j != 4; j++) {
										if (truthTable[i][j] != -1)
										continue;
										if (sequence[j] == Tristate::UNDEFINED)
										hasUndefined = true;
										else if (sequence[j] != truthTable[i][j])
										comparaisonSucceed = false;
									}

									if (comparaisonSucceed == true) {
										if (hasUndefined == true || i == 0 || i == 1)
											return (Tristate::UNDEFINED);
										else {
											if (i == 3 || i == 4) {
												return (this->getPin(c+1- 1)->compute());
											} else {
												return (this->getPin(c+1)->getState());
											}
										}
									}
								}
								return this->getPin(c+1)->getState();
							});
		} else if (c== 13 || c == 12 || c == 11 || c == 10) {
			_pins[c] =
					new Pin(
							[&, truthTable, c]() {
								int sequence[4] = {this->getPin(1)->compute(), this->getPin(15)->compute(), this->getPin(2)->compute(), this->getPin(3)->compute()};
								bool comparaisonSucceed = true;
								bool hasUndefined = false;
								int i = 0;

								for (; i != 6; i++, comparaisonSucceed = true, hasUndefined = false) {

									for (int j = 0; j != 4; j++) {
										if (truthTable[i][j] != -1)
										continue;
										if (sequence[j] == Tristate::UNDEFINED)
										hasUndefined = true;
										else if (sequence[j] != truthTable[i][j])
										comparaisonSucceed = false;
									}

									if (comparaisonSucceed == true) {
										if (hasUndefined == true || i == 0 || i == 1)
										return (Tristate::UNDEFINED);
										else {
											if (i == 3 || i == 4) {
												if (c == 13)
													return this->getPin(6+1)->compute();
												return (this->getPin(c+1+ 1)->compute());
											} else {
												return (this->getPin(c+1)->getState());
											}
										}
									}
								}
								return this->getPin(c+1)->getState();
							});
		} else if (c == 8) {
			_pins[c] =
					new Pin(
							[&, truthTable, c]() {
								int sequence[4] = {this->getPin(1)->compute(), this->getPin(15)->compute(), this->getPin(2)->compute(), this->getPin(3)->compute()};
								bool comparaisonSucceed = true;
								bool hasUndefined = false;
								int i = 0;

								for (; i != 6; i++, comparaisonSucceed = true, hasUndefined = false) {

									for (int j = 0; j != 4; j++) {
										if (truthTable[i][j] != -1)
										continue;
										if (sequence[j] == Tristate::UNDEFINED)
										hasUndefined = true;
										else if (sequence[j] != truthTable[i][j])
										comparaisonSucceed = false;
									}

									if (comparaisonSucceed == true) {
										if (hasUndefined == true || i == 0 || i == 1)
										return (Tristate::UNDEFINED);
										else {
											if (i == 1 || i == 5) {
												return (this->getPin(c+1)->getState());
											} else {
												return (this->getPin(1+11)->compute());
											}
										}
									}
								}
								return this->getPin(c+1)->getState();
							});
		} else if (c == 9) {
			_pins[c] =
					new Pin(
							[&, truthTable, c]() {
								int sequence[4] = {this->getPin(1)->compute(), this->getPin(15)->compute(), this->getPin(2)->compute(), this->getPin(3)->compute()};
								bool comparaisonSucceed = true;
								bool hasUndefined = false;
								int i = 0;

								for (; i != 6; i++, comparaisonSucceed = true, hasUndefined = false) {

									for (int j = 0; j != 4; j++) {
										if (truthTable[i][j] != -1)
										continue;
										if (sequence[j] == Tristate::UNDEFINED)
										hasUndefined = true;
										else if (sequence[j] != truthTable[i][j])
										comparaisonSucceed = false;
									}

									if (comparaisonSucceed == true) {
										if (hasUndefined == true || i == 0 || i == 1)
										return (Tristate::UNDEFINED);
										else {
											if (i == 1 || i == 5) {
												return (this->getPin(1+11)->compute());
											} else {
												return (this->getPin(c+1)->getState());
											}
										}
									}
								}
								return this->getPin(c+1)->getState();
							});
		} else {
			_pins[c] = new Pin([&, c]()->Tristate
			{
				class Pin *pin = this->getPin(c+1)->getLink();

				if (!pin)
				    return (this->getPin(c+1)->getState());
				return (pin->compute());
			});
		}
	}
}

Component4094::~Component4094()
{
	// TODO Auto-generated destructor stub
}

} /* namespace nts */
