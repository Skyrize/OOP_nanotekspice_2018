/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description:
** Gates
*/

#ifndef GATES_HPP_
	#define GATES_HPP_

#include "nts.hpp"

namespace nts {

    enum Side {
        LEFT = 0,
        RIGHT = 1
    };

    class Gates {
        public:
            Gates() = default;
            virtual ~Gates() = default;
            static Tristate AND(Tristate state1, Tristate state2);
            static Tristate OR(Tristate state1, Tristate state2);
            static Tristate NOR(Tristate state1, Tristate state2);
            static Tristate NAND(Tristate state1, Tristate state2);
            static Tristate XOR(Tristate state1, Tristate state2);
            static Tristate SUM(Tristate state1, Tristate state2,
                Tristate state3, Side side);

    };

}

#endif /* !GATES_HPP_ */
