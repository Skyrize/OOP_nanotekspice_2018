/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description:
** main
*/

#include "nts.hpp"
#include "Circuit.hpp"
#include "CommandLineInterpreter.hpp"
#include "NanoError.hpp"
#include "Parser.hpp"

int main(int ac, char **av)
{
    nts::Circuit *circuit = nullptr;
    nts::CommandLineInterpreter cli;

    if (ac == 1)
    	throw nts::UsageError();
    try {
    	nts::Parser parser(av[1]);
    	circuit = parser.processParsing(ac, av);
    } catch (nts::NanoError &e) {
    	std::cout << e.what() << std::endl;
    	return (84);
    }
    //cli.start(circuit);
    return 0;
}
