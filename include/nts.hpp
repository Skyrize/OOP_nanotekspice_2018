/*
 ** EPITECH PROJECT, 2019
 ** OOP_nanotekspice_2018
 ** File description:
 ** IComponent
 */

#ifndef ICOMPONENT_HPP_
#define ICOMPONENT_HPP_

#include "NanoError.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <memory>

namespace nts {

enum Tristate {
	UNDEFINED = (-true), TRUE = true, FALSE = false
};

class IComponent {
	public:
		virtual ~IComponent() = default;
		virtual nts::Tristate compute(size_t pin = 1) = 0;
		virtual void setLink(size_t pin, nts::IComponent &other,
				size_t otherPin) = 0;
		virtual void dump() const = 0;
		virtual class Pin *getPin(size_t pin) const = 0;
};

class Factory {
	public:
		static std::unique_ptr<IComponent> createComponent(const std::string &type,
				const std::string &value);

		static std::unique_ptr<IComponent> create2716(const std::string &value);
		static std::unique_ptr<IComponent> create4001(const std::string &value);
		static std::unique_ptr<IComponent> create4008(const std::string &value);
		static std::unique_ptr<IComponent> create4011(const std::string &value);
		static std::unique_ptr<IComponent> create4013(const std::string &value);
		static std::unique_ptr<IComponent> create4017(const std::string &value);
		static std::unique_ptr<IComponent> create4030(const std::string &value);
		static std::unique_ptr<IComponent> create4040(const std::string &value);
		static std::unique_ptr<IComponent> create4069(const std::string &value);
		static std::unique_ptr<IComponent> create4071(const std::string &value);
		static std::unique_ptr<IComponent> create4081(const std::string &value);
		static std::unique_ptr<IComponent> create4094(const std::string &value);
		static std::unique_ptr<IComponent> create4514(const std::string &value);
		static std::unique_ptr<IComponent> create4801(const std::string &value);
};
}

#endif /* !ICOMPONENT_HPP_ */
