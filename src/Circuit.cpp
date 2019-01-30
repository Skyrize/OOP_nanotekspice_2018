/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description:
** Circuit
*/

#include "Circuit.hpp"
#include "Pin.hpp"

nts::Circuit::Circuit()
{
}

void nts::Circuit::pushComponent(IComponent *component)
{
    _components.push_back(component);
}

void nts::Circuit::pushInput(IComponent *input)
{
    _inputs.push_back(input);
}

void nts::Circuit::pushOutput(IComponent *output)
{
    _outputs.push_back(output);
}

void nts::Circuit::display() const
{
    for (auto i : _outputs) {
        std::cout << i->getName() << "=" << i->getPin(0).getState() << std::endl;
    }
}

void nts::Circuit::setInputValue(const std::string &name, size_t value)
{
    for (auto i : _inputs) {
        if (name == i->getName()) {
            i->getPin(0).setState((Tristate)value);
        }
    }
}

void nts::Circuit::run()
{
    for (auto i : _outputs) {
        i->compute();
    }
}

void nts::Circuit::loop()
{
    while (1)
        run();
}

void nts::Circuit::dump() const
{
    for (auto i : _components)
        i->dump();
}