/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description:
** Circuit
*/

#include "Circuit.hpp"
#include "Pin.hpp"
#include "NanoError.hpp"

nts::Circuit::Circuit()
{
}

void nts::Circuit::pushComponent(IComponent *component)
{
	for (auto &e : _components) {
		if (e->getName() == component->getName()) {
			throw RedefinedComponentError("Several components share the same name : \'" + component->getName() + "\'");
		}
	}

    _components.push_back(component);
}

void nts::Circuit::pushInput(IComponent *input)
{
	for (auto &e : _inputs) {
		if (e->getName() == input->getName()) {
			throw RedefinedComponentError("Several components share the same name : \'" + input->getName() + "\'");
		}
	}
    _inputs.push_back(input);
}

void nts::Circuit::pushOutput(IComponent *output)
{
	for (auto &e : _outputs) {
		if (e->getName() == output->getName()) {
			throw RedefinedComponentError("Several components share the same name : \'" + output->getName() + "\'");
		}
	}
    _outputs.push_back(output);
}

void nts::Circuit::display() const
{
    for (auto &i : _outputs) {
        std::cout << i->getName() << "=" << i->getPin(0)->getState() << std::endl;
    }
}

void nts::Circuit::setInputValue(const std::string &name, size_t value)
{
    for (auto &i : _inputs) {
        if (name == i->getName()) {
            i->getPin(0)->setState((Tristate)value);
        }
    }
}

void nts::Circuit::run()
{
    for (auto &i : _outputs) {
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
    for (auto &i : _components)
        i->dump();
}
