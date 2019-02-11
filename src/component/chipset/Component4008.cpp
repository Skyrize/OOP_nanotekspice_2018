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
            _pins[i - 1] = new Pin([tab, i]()->Tristate
            {
                if (i == 10) {
                    return Gates::SUM(tab[9 - 1]->compute(),
                        tab[7 - 1]->compute(),
                        tab[6 - 1]->compute(), RIGHT);
                } else if (i == 11) {
                    return Gates::SUM(tab[4 - 1]->compute(), 
                        tab[5 - 1]->compute(),
                        Gates::SUM(tab[9 - 1]->compute(),
                        tab[7 - 1]->compute(),
                        tab[6 - 1]->compute(), LEFT), RIGHT);
                } else if (i == 12) {
                    return Gates::SUM(tab[2 - 1]->compute(),
                        tab[3 - 1]->compute(),
                        Gates::SUM(tab[4 - 1]->compute(), 
                        tab[5 - 1]->compute(),
                        Gates::SUM(tab[9 - 1]->compute(),
                        tab[7 - 1]->compute(),
                        tab[6 - 1]->compute(), LEFT), LEFT), RIGHT);
                } else if (i == 13) {
                    return Gates::SUM(tab[1 - 1]->compute(), 
                        tab[15 - 1]->compute(),
                        Gates::SUM(tab[2 - 1]->compute(),
                        tab[3 - 1]->compute(),
                        Gates::SUM(tab[4 - 1]->compute(), 
                        tab[5 - 1]->compute(),
                        Gates::SUM(tab[9 - 1]->compute(),
                        tab[7 - 1]->compute(),
                        tab[6 - 1]->compute(), LEFT), LEFT), LEFT), RIGHT);
                } else
                    return Gates::SUM(tab[1 - 1]->compute(), 
                        tab[15 - 1]->compute(),
                        Gates::SUM(tab[2 - 1]->compute(),
                        tab[3 - 1]->compute(),
                        Gates::SUM(tab[4 - 1]->compute(),
                        tab[5 - 1]->compute(),
                        Gates::SUM(tab[9 - 1]->compute(),
                        tab[7 - 1]->compute(),
                        tab[6 - 1]->compute(), LEFT), LEFT), LEFT), LEFT);
            });
        } else {
            _pins[i - 1] = new Pin([tab, i]()->Tristate
            {
                class Pin *pin = tab[i - 1]->getLink();

                if (!pin)
                    return (tab[i - 1]->getState());
                return (pin->compute());
            });
        }
    }
>>>>>>> b5adc6c591b09cae8c38780fdf58cc3d0fcb734b
}

Component4008::~Component4008()
{
	// TODO Auto-generated destructor stub
}

} /* namespace nts */
