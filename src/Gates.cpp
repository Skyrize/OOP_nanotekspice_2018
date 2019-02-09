/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description:
** Gates
*/

#include "nts.hpp"
#include "Gates.hpp"

namespace nts {

Tristate Gates::AND(Tristate state1, Tristate state2)
{
    if (state1 == FALSE || state2 == FALSE)
        return (FALSE);
    if (state1 == TRUE && state2 == TRUE)
        return (TRUE);
    return (UNDEFINED);
}

Tristate Gates::NAND(Tristate state1, Tristate state2)
{
    if (state1 == FALSE || state2 == FALSE)
        return (TRUE);
    if (state1 == TRUE && state2 == TRUE)
        return (FALSE);
    return (UNDEFINED);
}

Tristate Gates::OR(Tristate state1, Tristate state2)
{
    if (state1 == TRUE || state2 == TRUE)
        return (TRUE);
    if (state1 == FALSE && state2 == FALSE)
        return (FALSE);
    return (UNDEFINED);
}

Tristate Gates::NOR(Tristate state1, Tristate state2)
{
    if (state1 == TRUE || state2 == TRUE)
        return (FALSE);
    if (state1 == FALSE && state2 == FALSE)
        return (TRUE);
    return (UNDEFINED);
}

Tristate Gates::XOR(Tristate state1, Tristate state2)
{
    if (state1 == UNDEFINED || state2 == UNDEFINED)
        return (UNDEFINED);
    if (state1 == state2)
        return (FALSE);
    return (TRUE);
}

Tristate Gates::SUM(Tristate state1, Tristate state2, Tristate state3, Side side)
{
    Tristate states[2];
    int x = 0;

    if (state1 == TRUE)
        x++;
    if (state2 == TRUE)
        x++;
    if (state3 == TRUE)
        x++;
    if (state1 == UNDEFINED || state2 == UNDEFINED || state3 == UNDEFINED)
        return (UNDEFINED);
    if (x == 0)
        return (FALSE);
    else if (x == 1) {
        states[0] = FALSE;
        states[1] = TRUE;
    } else if (x == 2) {
        states[0] = TRUE;
        states[1] = FALSE;
    } else {
        states[0] = TRUE;
        states[1] = TRUE;
    }
    return (states[(int)side]);
}

}