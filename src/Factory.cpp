/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description: Created on: 30 janv. 2019
** Factory.cpp
*/

#include <map>
#include <memory>
#include "nts.hpp"
#include "Component2716.hpp"
#include "Component4001.hpp"
#include "Component4008.hpp"
#include "Component4011.hpp"
#include "Component4013.hpp"
#include "Component4017.hpp"
#include "Component4030.hpp"
#include "Component4040.hpp"
#include "Component4069.hpp"
#include "Component4071.hpp"
#include "Component4081.hpp"
#include "Component4094.hpp"
#include "Component4514.hpp"
#include "Component4801.hpp"

using methodPtr = std::unique_ptr<nts::IComponent> (*)(const std::string &value);

static const std::map<std::string, methodPtr> methodPointers = {
		{"2716", &nts::Factory::create2716},
		{"4001", &nts::Factory::create4001},
		{"4001", &nts::Factory::create4008},
		{"4001", &nts::Factory::create4011},
		{"4001", &nts::Factory::create4013},
		{"4001", &nts::Factory::create4017},
		{"4001", &nts::Factory::create4030},
		{"4001", &nts::Factory::create4040},
		{"4001", &nts::Factory::create4069},
		{"4001", &nts::Factory::create4071},
		{"4001", &nts::Factory::create4081},
		{"4001", &nts::Factory::create4094},
		{"4001", &nts::Factory::create4514},
		{"4001", &nts::Factory::create4801},
};

std::unique_ptr<nts::IComponent> nts::Factory::createComponent(const std::string &type,
				const std::string &value)
{
}

std::unique_ptr<nts::IComponent> nts::Factory::create2716(const std::string &value)
{
	return std::unique_ptr<IComponent>(new Component2716(value));
}

std::unique_ptr<nts::IComponent> nts::Factory::create4001(const std::string &value)
{
	return std::unique_ptr<IComponent>(new Component4001(value));
}

std::unique_ptr<nts::IComponent> nts::Factory::create4008(const std::string &value)
{
	return std::unique_ptr<IComponent>(new Component4008(value));
}

std::unique_ptr<nts::IComponent> nts::Factory::create4011(const std::string &value)
{
	return std::unique_ptr<IComponent>(new Component4011(value));
}

std::unique_ptr<nts::IComponent> nts::Factory::create4013(const std::string &value)
{
	return std::unique_ptr<IComponent>(new Component4013(value));
}

std::unique_ptr<nts::IComponent> nts::Factory::create4017(const std::string &value)
{
	return std::unique_ptr<IComponent>(new Component4017(value));
}

std::unique_ptr<nts::IComponent> nts::Factory::create4030(const std::string &value)
{
	return std::unique_ptr<IComponent>(new Component4030(value));
}

std::unique_ptr<nts::IComponent> nts::Factory::create4040(const std::string &value)
{
	return std::unique_ptr<IComponent>(new Component4040(value));
}

std::unique_ptr<nts::IComponent> nts::Factory::create4069(const std::string &value)
{
	return std::unique_ptr<IComponent>(new Component4069(value));
}

std::unique_ptr<nts::IComponent> nts::Factory::create4071(const std::string &value)
{
	return std::unique_ptr<IComponent>(new Component4071(value));
}

std::unique_ptr<nts::IComponent> nts::Factory::create4081(const std::string &value)
{
	return std::unique_ptr<IComponent>(new Component4081(value));
}

std::unique_ptr<nts::IComponent> nts::Factory::create4094(const std::string &value)
{
	return std::unique_ptr<IComponent>(new Component4094(value));
}

std::unique_ptr<nts::IComponent> nts::Factory::create4514(const std::string &value)
{
	return std::unique_ptr<IComponent>(new Component4514(value));
}

std::unique_ptr<nts::IComponent> nts::Factory::create4801(const std::string &value)
{
	return std::unique_ptr<IComponent>(new Component4801(value));
}


