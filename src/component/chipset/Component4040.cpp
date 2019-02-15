/*
 ** EPITECH PROJECT, 2019
 ** OOP_nanotekspice_2018
 ** File description: Created on: 30 janv. 2019
 ** Component4040.cpp
 */

#include "Component4040.hpp"

namespace nts {

Component4040::Component4040(const std::string& name)
: Component(name)
{
	_pins = std::vector<Pin *>(16);

	for (int i = 0; i != 16; i++) {
		if (i == 10) {
			_pins[i] = new Pin([&, i]()
			{
				if (this->getPin(i + 1)->getState() == Tristate::TRUE)
					this->resetMemoryClock();
				return this->getPin(i + 1)->getState();
			});

		} else if ((i >= 0 && i <= 6) || i == 8 || (i >= 11 && i <= 14)) {
			_pins[i] = new Pin([&, i]()
			{
				if (this->getPin(11)->getState() == Tristate::TRUE) {
					return Tristate::FALSE;
				} else if (this->getPin(11)->getState() == Tristate::UNDEFINED) {
					return Tristate::UNDEFINED;
				} else {
					return this->getOutputStatus(i + 1);
				}
			});
		} else {
			_pins[i] = new Pin([&, i]()
			{
			    class Pin *pin = this->getPin(i + 1)->getLink();

			    if (!pin)
			        return (this->getPin(i + 1)->getState());
			    return (pin->compute());
			});
		}
	}
}

Tristate Component4040::getOutputStatus(size_t outputPin)
{
	int tab[12][2] = {
		{1, 9},
		{2, 7},
		{4, 6},
		{8, 5},
		{16, 3},
		{32, 2},
		{64, 4},
		{128, 13},
		{256, 12},
		{512, 14},
		{1024, 15},
		{2048, 1}
		};

		if (this->memoryClock >= 4096)
			return Tristate::FALSE;
		for (int i = 0; i != 12; i++) {
			if (i != 11 && tab[i + 1][0] == this->memoryClock && tab[i + 1][1] == outputPin) {
				return Tristate::FALSE;
			}
			if (tab[i][0] == this->memoryClock && tab[i][1] == outputPin) {
				return Tristate::TRUE;
			}
		}
		return this->getPin(outputPin)->getState();
}


void Component4040::incrementMemoryClock()
{
	this->memoryClock++;
}

void Component4040::resetMemoryClock()
{
	this->memoryClock = 0;
	for (int i = 0; i != 16; i++)
		if ((i >= 0 && i <= 6) || i == 8 || (i >= 11 && i <= 14))
			_pins[i]->setState(nts::FALSE);
}

Component4040::~Component4040()
{
	// TODO Auto-generated destructor stub
}

} /* namespace nts */
