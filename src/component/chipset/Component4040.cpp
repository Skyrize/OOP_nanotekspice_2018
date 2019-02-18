/*
 ** EPITECH PROJECT, 2019
 ** OOP_nanotekspice_2018
 ** File description: Created on: 30 janv. 2019
 ** Component4040.cpp
 */

#include "Component4040.hpp"
#include <map>

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
				Tristate computed = this->getPin(i + 1)->getState();

			    if (pin)
			        computed = pin->compute();
				if (computed == Tristate::TRUE)
					this->resetMemoryClock();
			    return (computed);
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
				if (computed == Tristate::FALSE && this->getPreviousClockState() == Tristate::TRUE) {
						this->incrementMemoryClock();
				}
				 this->setPreviousClockState(computed);
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
	int binary[12] = {0};
	int clock = this->memoryClock;

	if (this->memoryClock >= 4096)
		return Tristate::FALSE;
	for (int i = 0; i != 12; i++) {
		binary[i] = clock % 2;
		clock = clock / 2;
	}
	std::map<size_t, int> outputs = {
		{9, 0},
		{7, 1},
		{6, 2},
		{5, 3},
		{3, 4},
		{2, 5},
		{4, 6},
		{13, 7},
		{12, 8},
		{14, 9},
		{15, 10},
		{1, 11}
		};
	return (Tristate)binary[outputs[outputPin]];
}


void Component4040::incrementMemoryClock()
{
	this->memoryClock++;
}

void Component4040::resetMemoryClock()
{
	this->memoryClock = 0;
	this->previousClockState = Tristate::UNDEFINED;
	for (int i = 0; i != 16; i++)
		if ((i >= 0 && i <= 6) || i == 8 || (i >= 11 && i <= 14))
			_pins[i]->setState(Tristate::FALSE);
}

Component4040::~Component4040()
{
	// TODO Auto-generated destructor stub
}

} /* namespace nts */
