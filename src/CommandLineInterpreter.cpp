/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description:
** CommandLineInterpreter
*/

#include "CommandLineInterpreter.hpp"
#include "Circuit.hpp"
#include <map>

nts::CommandLineInterpreter::CommandLineInterpreter()
{
    _map["exit"] = &my_exit;
    _map["display"] = &display;
    _map["simulate"] = &simulate;
    _map["loop"] = &loop;
    _map["dump"] = &dump;
}

void nts::CommandLineInterpreter::my_exit(nts::Circuit circuit) const
{
    (void)circuit;
    exit(0);
}

void nts::CommandLineInterpreter::display(nts::Circuit circuit) const
{
    circuit.display();
}

void nts::CommandLineInterpreter::simulate(nts::Circuit circuit) const
{
    circuit.run();
}

void nts::CommandLineInterpreter::loop(nts::Circuit circuit) const
{
    circuit.loop();
}

void nts::CommandLineInterpreter::dump(nts::Circuit circuit) const
{
    circuit.dump();
}

void nts::CommandLineInterpreter::start()
{
    nts::Circuit circuit;

    while (1) {
        getLine();
        // TODO setInputValue
        if (_map[_cmd]) {
            _map[_cmd](circuit);
        }
    }
}

void nts::CommandLineInterpreter::getLine()
{
    std::string cmd;

    std::cout << "> ";
    std::getline(std::cin, cmd);
    if (std::cin.eof())
        exit (0);
    _cmd = cmd;
}