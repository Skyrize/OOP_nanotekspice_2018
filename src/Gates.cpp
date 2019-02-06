/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description:
** Gates
*/

#include "nts.hpp"

nts::Tristate nts::Gates::AND(nts::Tristate state1, nts::Tristate state2)
{
    if (state1 == FALSE || state2 == FALSE)
        return (FALSE);
    if (state1 == TRUE && state2 == TRUE)
        return (TRUE);
    return (UNDEFINED);
}

nts::Tristate nts::Gates::NAND(nts::Tristate state1, nts::Tristate state2)
{
    if (state1 == FALSE || state2 == FALSE)
        return (TRUE);
    if (state1 == TRUE && state2 == TRUE)
        return (FALSE);
    return (UNDEFINED);
}

nts::Tristate nts::Gates::OR(nts::Tristate state1, nts::Tristate state2)
{
    if (state1 == TRUE || state2 == TRUE)
        return (TRUE);
    if (state1 == FALSE && state2 == FALSE)
        return (FALSE);
    return (UNDEFINED);
}

nts::Tristate nts::Gates::NOR(nts::Tristate state1, nts::Tristate state2)
{
    if (state1 == TRUE || state2 == TRUE)
        return (FALSE);
    if (state1 == FALSE && state2 == FALSE)
        return (TRUE);
    return (UNDEFINED);
}

nts::Tristate nts::Gates::XOR(nts::Tristate state1, nts::Tristate state2)
{
    if (state1 == UNDEFINED || state2 == UNDEFINED)
        return (UNDEFINED);
    if (state1 == state2)
        return (FALSE);
    return (TRUE);
}