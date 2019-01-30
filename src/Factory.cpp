/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description: Created on: 30 janv. 2019
** Factory.cpp
*/

#include <map>
#include <memory>
#include "NanoError.hpp"
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

namespace nts {
namespace Factory {

using methodPtr = std::unique_ptr<IComponent> (*)(const std::string &value);

static std::map<const std::string, methodPtr> methodPointers = {
		{"2716", &create2716},
		{"4001", &create4001},
		{"4001", &create4008},
		{"4001", &create4011},
		{"4001", &create4013},
		{"4001", &create4017},
		{"4001", &create4030},
		{"4001", &create4040},
		{"4001", &create4069},
		{"4001", &create4071},
		{"4001", &create4081},
		{"4001", &create4094},
		{"4001", &create4514},
		{"4001", &create4801},
};

std::unique_ptr<IComponent> createComponent(const std::string &type, std::string &value)
{
	if (!methodPointers[type]) {
		throw ComponentTypeError();
	}
	return (methodPointers[type](value));
}

std::unique_ptr<IComponent> create2716(const std::string &value)
{
	return std::unique_ptr<IComponent>(new Component2716(value));
}

std::unique_ptr<IComponent> create4001(const std::string &value)
{
	return std::unique_ptr<IComponent>(new Component4001(value));
}

std::unique_ptr<IComponent> create4008(const std::string &value)
{
	return std::unique_ptr<IComponent>(new Component4008(value));
}

std::unique_ptr<IComponent> create4011(const std::string &value)
{
	return std::unique_ptr<IComponent>(new Component4011(value));
}

std::unique_ptr<IComponent> create4013(const std::string &value)
{
	return std::unique_ptr<IComponent>(new Component4013(value));
}

std::unique_ptr<IComponent> create4017(const std::string &value)
{
	return std::unique_ptr<IComponent>(new Component4017(value));
}

std::unique_ptr<IComponent> create4030(const std::string &value)
{
	return std::unique_ptr<IComponent>(new Component4030(value));
}

std::unique_ptr<IComponent> create4040(const std::string &value)
{
	return std::unique_ptr<IComponent>(new Component4040(value));
}

std::unique_ptr<IComponent> create4069(const std::string &value)
{
	return std::unique_ptr<IComponent>(new Component4069(value));
}

std::unique_ptr<IComponent> create4071(const std::string &value)
{
	return std::unique_ptr<IComponent>(new Component4071(value));
}

std::unique_ptr<IComponent> create4081(const std::string &value)
{
	return std::unique_ptr<IComponent>(new Component4081(value));
}

std::unique_ptr<IComponent> create4094(const std::string &value)
{
	return std::unique_ptr<IComponent>(new Component4094(value));
}

std::unique_ptr<IComponent> create4514(const std::string &value)
{
	return std::unique_ptr<IComponent>(new Component4514(value));
}

std::unique_ptr<IComponent> create4801(const std::string &value)
{
	return std::unique_ptr<IComponent>(new Component4801(value));
}

}
}

