/*
 ** EPITECH PROJECT, 2019
 ** OOP_nanotekspice_2018
 ** File description: Created on: 30 janv. 2019
 ** Component4017.cpp
 */

#include "Component4017.hpp"
#include <map>

namespace nts {

Component4017::Component4017(const std::string& name)
: Component(name)
{
	_pins = std::vector<Pin *>(15);
    short arr[10] = {3, 2, 4, 7, 10 ,1, 5, 6, 9, 11};

	for (int i = 1; i != 16; i++) {
        if (i != 13 && i != 14 && i != 15) {
            _pins[i - 1] = new Pin([&, i, arr]()->Tristate
            {
                Tristate state0 = this->getPin(14)->compute();
                Tristate state1 = this->getPin(13)->compute();
                Tristate reset = this->getPin(15)->compute();

                if (state0 == UNDEFINED && state1 == UNDEFINED)
                    return UNDEFINED;
                ///// SEQUENCE
                Tristate prevState0 = this->getPreviousCp0();
                Tristate prevState1 = this->getPreviousCp1();
                short sequence = this->getSequence();

                // std::cout << sequence << std::endl;
                // std::cout << prevState0 << std::endl;
                // std::cout << prevState1 << std::endl;
                this->setPreviousCp0(state0);
                this->setPreviousCp1(state1);
                if ((state0 == TRUE && prevState0 == FALSE)
                || (state1 == FALSE && prevState1 == TRUE)) {
                    if (sequence == 9) {
                        sequence = 0;
                        this->getPin(12)->setState(TRUE);
                    } else
                        sequence++;
                    this->setSequence(sequence);
                    if (sequence == 5)
                        this->getPin(12)->setState(FALSE);
                    this->getPin(arr[sequence])->setState(TRUE);
                    if (sequence == 0)
                        this->getPin(arr[9])->setState(FALSE);
                    else
                        this->getPin(arr[sequence - 1])->setState(FALSE);
                }
                ///// RESET
                if (reset == TRUE) {
                    this->setSequence(0);
                    this->getPin(3)->setState(TRUE);
                    this->getPin(12)->setState(TRUE);
                    for (int i = 1; i < 10; i++)
                        this->getPin(arr[i])->setState(FALSE);
                }
                return this->getPin(i)->getState();
            });
        } else {
            _pins[i - 1] = new Pin([&, i]()->Tristate
            {
                class Pin *pin = this->getPin(i)->getLink();

                if (!pin)
                    return (this->getPin(i)->getState());
                return (pin->compute());
            });
        }
    }
    _pins[3 - 1]->setState(TRUE);
    _pins[12 - 1]->setState(TRUE);
    for (int i = 1; i < 10; i++)
        _pins[arr[i] - 1]->setState(FALSE);
}

Component4017::~Component4017()
{
	// TODO Auto-generated destructor stub
}

} /* namespace nts */
