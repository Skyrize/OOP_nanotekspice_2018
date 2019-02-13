/*
 ** EPITECH PROJECT, 2019
 ** OOP_nanotekspice_2018
 ** File description: Created on: 30 janv. 2019
 ** Component4008.cpp
 */

#include "Component4008.hpp"

namespace nts {

Component4008::Component4008(const std::string& name)
: Component(name)
{
    _pins = std::vector<Pin *>(16);
    std::vector<nts::Pin *> tab = _pins;

	for (int i = 1; i < 17; i++) {
        if (i == 10 || i == 11 || i == 12 || i == 13 || i == 14) {
            _pins[i - 1] = new Pin([&, i]()->Tristate
            {
                if (i == 10) {
                    return Gates::SUM(this->getPin(9)->compute(),
                        this->getPin(7)->compute(),
                        this->getPin(6)->compute(), RIGHT);
                } else if (i == 11) {
                    return Gates::SUM(this->getPin(4)->compute(), 
                        this->getPin(5)->compute(),
                        Gates::SUM(this->getPin(9)->compute(),
                        this->getPin(7)->compute(),
                        this->getPin(6)->compute(), LEFT), RIGHT);
                } else if (i == 12) {
                    return Gates::SUM(this->getPin(2)->compute(),
                        this->getPin(3)->compute(),
                        Gates::SUM(this->getPin(4)->compute(), 
                        this->getPin(5)->compute(),
                        Gates::SUM(this->getPin(9)->compute(),
                        this->getPin(7)->compute(),
                        this->getPin(6)->compute(), LEFT), LEFT), RIGHT);
                } else if (i == 13) {
                    return Gates::SUM(this->getPin(1)->compute(), 
                        this->getPin(15)->compute(),
                        Gates::SUM(this->getPin(2)->compute(),
                        this->getPin(3)->compute(),
                        Gates::SUM(this->getPin(4)->compute(), 
                        this->getPin(5)->compute(),
                        Gates::SUM(this->getPin(9)->compute(),
                        this->getPin(7)->compute(),
                        this->getPin(6)->compute(), LEFT), LEFT), LEFT), RIGHT);
                } else
                    return Gates::SUM(this->getPin(1)->compute(), 
                        this->getPin(15)->compute(),
                        Gates::SUM(this->getPin(2)->compute(),
                        this->getPin(3)->compute(),
                        Gates::SUM(this->getPin(4)->compute(),
                        this->getPin(5)->compute(),
                        Gates::SUM(this->getPin(9)->compute(),
                        this->getPin(7)->compute(),
                        this->getPin(6)->compute(), LEFT), LEFT), LEFT), LEFT);
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
}

Component4008::~Component4008()
{
	// TODO Auto-generated destructor stub
}

} /* namespace nts */
