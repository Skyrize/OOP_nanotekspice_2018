/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description:
** Component4081
*/

#ifndef COMPONENT4081_HPP_
#define COMPONENT4081_HPP_

#include "nts.hpp"

namespace nts {

    class Component4081 : public IComponent {
        public:
            Component4081();
            virtual ~Component4081() = default;
            nts::Tristate compute(size_t pin = 1) override;
            void setLink(size_t pin, nts::IComponent &other, size_t otherPin) override;
            void dump() const override;
            class Pin *getPin(size_t pin) const override;

        private:
            class Pin *_pins[14];
    };

}

#endif /* !COMPONENT4081_HPP_ */
