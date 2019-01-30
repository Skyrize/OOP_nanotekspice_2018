/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description:
** IComponent
*/

#ifndef ICOMPONENT_HPP_
#define ICOMPONENT_HPP_

#include "NanoError.hpp"
#include <iostream>
#include <vector>
#include <list>

namespace nts {
    
    enum Tristate {
        UNDEFINED = (-true),
        TRUE = true,
        FALSE = false
    };

    class IComponent {
        public:
            virtual ~IComponent() = default;
            virtual nts::Tristate compute(size_t pin = 1) = 0;
            virtual void setLink(size_t pin, nts::IComponent &other, size_t otherPin) = 0;
            virtual void dump() const = 0;
            virtual class Pin *getPin(size_t pin) const = 0;
    };
}

#endif /* !ICOMPONENT_HPP_ */
