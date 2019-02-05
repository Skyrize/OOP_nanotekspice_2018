/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description:
** main
*/

#include "nts.hpp"
#include "Parser.hpp"
#include "NanoError.hpp"
#include "Pin.hpp"

int main(int ac, char **av)
{
    if (ac == 1)
    	throw nts::UsageError();
    nts::Pin prout;

	nts::Parser parser(av[1]);
	parser.processParsing(ac, av);



    return 0;
}
