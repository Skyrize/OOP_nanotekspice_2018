/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description:
** CommandLineInterpreter
*/

#include "CommandLineInterpreter.hpp"
#include "Input.hpp"

nts::CommandLineInterpreter::CommandLineInterpreter()
{
    _map["exit"] = &nts::CommandLineInterpreter::my_exit;
    _map["display"] = &nts::CommandLineInterpreter::display;
    _map["simulate"] = &nts::CommandLineInterpreter::simulate;
    _map["loop"] = &nts::CommandLineInterpreter::loop;
    _map["dump"] = &nts::CommandLineInterpreter::dump;
}

void nts::CommandLineInterpreter::my_exit(nts::Circuit *circuit) const
{
    (void)circuit;
    exit(0);
}

void nts::CommandLineInterpreter::display(nts::Circuit *circuit) const
{
    circuit->display();
}

void nts::CommandLineInterpreter::simulate(nts::Circuit *circuit) const
{
    circuit->run();
}

void nts::CommandLineInterpreter::loop(nts::Circuit *circuit) const
{
    circuit->loop();
}

void nts::CommandLineInterpreter::dump(nts::Circuit *circuit) const
{
    circuit->dump();
}

void nts::CommandLineInterpreter::setInputValue(nts::Circuit *circuit) const
{
    std::string name;
    size_t value;
    size_t pos = 0;
    std::vector<std::unique_ptr<IComponent>> &vec = circuit->getInputs();
    bool inputFound = 0;

    pos = _cmd.find('=');
    name = _cmd.substr(0, pos);
    for (auto &i : vec) {
        if (!i.get()->getName().compare(name))
            inputFound = 1;
    }
    if (name.empty() || !inputFound) {
        std::cerr << "Please enter a valid input name" << std::endl;
        return;
    }
    value = atoi(_cmd.substr(pos + 1).c_str());
    if (value != 1 && value != 0) {
        std::cerr << "Please enter a valid input value" << std::endl;
        return;
    }
    circuit->setInputValue(name, value);
}

void nts::CommandLineInterpreter::start(nts::Circuit *circuit)
{
    while (1) {
        getLine();
        if (_cmd.find('=') != std::string::npos) {
            setInputValue(circuit);
        } else if (_map[_cmd])
            (this->*_map[_cmd])(circuit);
        else
            std::cerr << "Please enter a valid command." << std::endl;
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
