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
			    class Pin *pin = this->getPin(i + 1)->getLink();

			    if (!pin) {
					if (this->getPin(i + 1)->getState() == Tristate::TRUE)
						this->resetMemoryClock();
			        return (this->getPin(i + 1)->getState());
				}
				if (pin->getState() == Tristate::TRUE)
					this->resetMemoryClock();
			    return (pin->compute());
			});

		} else if ((i >= 0 && i <= 6) || i == 8 || (i >= 11 && i <= 14)) {
			_pins[i] = new Pin([&, i]()
			{
				Tristate resetState = this->getPin(11)->compute();
				this->getPin(10)->compute();
				if (resetState == Tristate::TRUE) {
					return Tristate::FALSE;
				} else if (resetState == Tristate::UNDEFINED) {
					return Tristate::UNDEFINED;
				} else {
					return this->getOutputStatus(i + 1);
				}
			});
		} else {
			_pins[i] = new Pin([&, i]()
			{
			    class Pin *pin = this->getPin(i + 1)->getLink();
				Tristate computed = this->getPin(i + 1)->getState();

			    if (pin)
			        computed = pin->compute();
				if (this->getPreviousClockState() != computed) {
					if (this->isClockStarting() == true && computed == Tristate::TRUE)
						this->incrementMemoryClock();
					this->incrementMemoryClock();
					this->setPreviousClockState(computed);
				}
			    return (computed);
			});
		}
	}
}

Tristate Component4040::getPreviousClockState()
{
	return this->previousClockState;
}

void Component4040::setPreviousClockState(Tristate state)
{
	this->previousClockState = state;
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
			if (tab[i][0] == this->memoryClock && tab[i][1] == outputPin) {
				this->openPin = outputPin;
			}
			if (i != 11 && tab[i + 1][0] == this->memoryClock && tab[i][1] == outputPin) {
				this->getPin(tab[i][1])->setState(Tristate::FALSE);
				this->openPin = 0;
			}
		}
		if (this->openPin == outputPin)
			return Tristate::TRUE;
		return Tristate::FALSE;
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
