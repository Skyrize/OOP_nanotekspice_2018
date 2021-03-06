/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description:
** Circuit
*/

#include "Circuit.hpp"
#include "Pin.hpp"
#include "NanoError.hpp"
#include "Clock.hpp"
#include <algorithm>

nts::Circuit::Circuit()
{
}

void nts::Circuit::pushComponent(std::unique_ptr<IComponent> &component)
{
	for (auto &e : _components) {
		if (e->getName() == component->getName()) {
			throw RedefinedComponentError("Several components share the same name : \'" + component->getName() + "\'");
		}
	}

    _components.push_back(std::move(component));
}

void nts::Circuit::pushInput(std::unique_ptr<IComponent> &input)
{
	for (auto &e : _inputs) {
		if (e->getName() == input->getName()) {
			throw RedefinedComponentError("Several components share the same name : \'" + input->getName() + "\'");
		}
	}
    _inputs.push_back(std::move(input));
}

void nts::Circuit::pushOutput(std::unique_ptr<IComponent> &output)
{
	for (auto &e : _outputs) {
		if (e->getName() == output->getName()) {
			throw RedefinedComponentError("Several components share the same name : \'" + output->getName() + "\'");
		}
	}
    _outputs.push_back(std::move(output));
    std::sort(_outputs.begin(), _outputs.end(),
    [](std::unique_ptr<IComponent> &a, std::unique_ptr<IComponent> &b) {
        return a.get()->getName() < b.get()->getName();
    });
}

void nts::Circuit::display() const
{
    Tristate state = UNDEFINED;

    for (auto &i : _outputs) {
        state = i->getPin(1)->getState();
        std::cout << i->getName() << "=";
        if (state == UNDEFINED)
            std::cout << "U" << std::endl;
        else
            std::cout << state << std::endl;
    }
}

void nts::Circuit::setInputValue(const std::string &name, size_t value)
{
    for (auto &i : _inputs) {
        if (name == i->getName()) {
            if (dynamic_cast<nts::Clock *>(i.get())) {
                std::cerr << "Please give a valid input." << std::endl;
                return;
            }
            i->getPin(1)->setState((Tristate)value);
        }
    }
}

void nts::Circuit::run()
{
    Clock *c = nullptr;
    Tristate state = UNDEFINED;

    for (auto &i : _outputs) {
        i->compute(1);
    }
    for (auto &i : _inputs) {
        if (c = dynamic_cast<nts::Clock *>(i.get())) {
            state = c->getPin(1)->getState();
            c->getPin(1)->setState(state == TRUE ? FALSE : TRUE);
        }
    }
}

void nts::Circuit::loop()
{
    while (1);
        // run();
}

void nts::Circuit::dump() const
{
    std::cout << "Inputs:" << std::endl;
    for (auto &i : _inputs) {
        std::cout << std::endl;
        i->dump();
    }
    std::cout << std::endl;
    std::cout << "Outputs:" << std::endl;
    for (auto &i : _outputs) {
        std::cout << std::endl;
        i->dump();
    }
    std::cout << std::endl;
    std::cout << "Components:" << std::endl;
    for (auto &i : _components) {
        std::cout << std::endl;
        i->dump();
    }
}
