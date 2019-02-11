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
	std::vector<nts::Pin *> tab = _pins;

	int truthTable[5][6] = { { 1, 0, -2, -2 }, { 0, 0, -2, -2 },
			{ 1, 1, 0, -2 }, { 1, 1, 1, 0 }, { 1, 1, 1, 1 }, { 0, 1, 1, 1 } };

	for (int c = 0; c != 16; c++) {
		if (c == 3) {
			_pins[c] =
					new Pin(
							[tab, truthTable, c]() {
								int sequence[4] = {tab[0]->compute(), tab[1]->compute(), tab[2]->compute(), tab[3]->compute()};
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
												return (tab[c]->getState());
											}
										}
									}
								}
								return tab[c]->getState();
							});
		} else if (c == 4 || c == 5 || c == 6) {
			_pins[c] =
					new Pin(
							[tab, truthTable, c]() {
								int sequence[4] = {tab[0]->compute(), tab[1]->compute(), tab[2]->compute(), tab[3]->compute()};
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
												return (tab[c - 1]->getState());
											} else {
												return (tab[c]->getState());
											}
										}
									}
								}
								return tab[c]->getState();
							});
		} else if (c == 13 || c == 12 || c == 11) {
			_pins[c] =
					new Pin(
							[tab, truthTable, c]() {
								int sequence[4] = {tab[0]->compute(), tab[1]->compute(), tab[2]->compute(), tab[3]->compute()};
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
												return tab[6]->getState();
												return (tab[c + 1]->getState());
											} else {
												return (tab[c]->getState());
											}
										}
									}
								}
								return tab[c]->getState();
							});
		} else if (c == 8) {
			_pins[c] =
					new Pin(
							[tab, truthTable, c]() {
								int sequence[4] = {tab[0]->compute(), tab[1]->compute(), tab[2]->compute(), tab[3]->compute()};
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
												return (tab[c]->getState());
											} else {
												return (tab[11]->getState());
											}
										}
									}
								}
								return tab[c]->getState();
							});
		} else if (c == 9) {
			_pins[c] =
					new Pin(
							[tab, truthTable, c]() {
								int sequence[4] = {tab[0]->compute(), tab[1]->compute(), tab[2]->compute(), tab[3]->compute()};
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
												return (tab[11]->getState());
											} else {
												return (tab[c]->getState());
											}
										}
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

Component4094::~Component4094()
{
	// TODO Auto-generated destructor stub
}

} /* namespace nts */
