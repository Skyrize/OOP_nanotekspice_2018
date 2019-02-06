/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description:
** main
*/

#include "nts.hpp"
#include "Parser.hpp"
#include "NanoError.hpp"
#include "Circuit.hpp"
#include "CommandLineInterpreter.hpp"
#include "Pin.hpp"

int main(int ac, char **av)
{
    nts::Circuit *circuit = nullptr;
    nts::CommandLineInterpreter cli;

    if (ac == 1)
    	throw nts::UsageError();
    nts::Parser parser(av[1]);
	circuit = parser.processParsing(ac, av);
    cli.start(circuit);
    return 0;
}
