/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description:
** Component4081
*/

#include "Component4081.hpp"

nts::Component4081::Component4081()
{

}

class nts::Pin *nts::Component4081::getPin(size_t pin) const
{
    return _pins[pin - 1];
}

void nts::Component4081::setLink(size_t pin, nts::IComponent &other, size_t otherPin)
{
    // class Pin *tmp = _pins[pin - 1];

    // tmp->setLink()
}