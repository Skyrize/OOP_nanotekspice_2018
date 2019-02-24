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
#include "string.h"
#include <signal.h>
#include <exception>

void sig_handler(int n)
{
    std::cerr << "Error" << std::endl;
    exit (84);
}

int main(int ac, char **av)
{
    nts::Circuit *circuit = nullptr;
    nts::CommandLineInterpreter cli;

    signal(SIGSEGV, &sig_handler);
    signal(SIGABRT, &sig_handler);
    if (ac == 1
    || (ac == 2 && (!strcmp(av[1], "-h") || !strcmp(av[1], "--help")))) {
    	std::cout << "Usage: ./nanotekspice [circuit_file.nts] " <<
        "[component=value ...]" << std::endl;
        return 84;
    }
    try {
    	nts::Parser parser(av[1]);
    	circuit = parser.processParsing(ac, av);
    	cli.start(circuit);
    } catch (nts::NanoError &e) {
    	std::cerr << e.what() << std::endl;
    	return 84;
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }
    return 0;
}
