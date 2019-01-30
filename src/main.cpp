/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description:
** main
*/

#include "nts.hpp"
#include "Parser.hpp"
#include "NanoError.hpp"

int main(int ac, char **av)
{
    if (ac == 1)
    	throw nts::UsageError();

	nts::Parser parser(av[1]);
	parser.processParsing();



    return 0;
}
