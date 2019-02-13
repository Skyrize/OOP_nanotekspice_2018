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

    if (ac == 1) {
    	std::cout << nts::UsageError().what() << std::endl;
    	return (1);
    }
    try {
    	nts::Parser parser(av[1]);
    	circuit = parser.processParsing(ac, av);
    	cli.start(circuit);
    } catch (nts::NanoError &e) {
    	std::cout << e.what() << std::endl;
    	return (1);
    }
    return 0;
}
