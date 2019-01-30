/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description: Created on: 30 janv. 2019
** Factory.hpp
*/

#ifndef INCLUDE_FACTORY_HPP_
#define INCLUDE_FACTORY_HPP_

#include "nts.hpp"

namespace nts {

	namespace Factory {
		std::unique_ptr<IComponent> createComponent(std::string &type, const std::string &value);

		std::unique_ptr<IComponent> create2716(const std::string &value);
		std::unique_ptr<IComponent> create4001(const std::string &value);
		std::unique_ptr<IComponent> create4008(const std::string &value);
		std::unique_ptr<IComponent> create4011(const std::string &value);
		std::unique_ptr<IComponent> create4013(const std::string &value);
		std::unique_ptr<IComponent> create4017(const std::string &value);
		std::unique_ptr<IComponent> create4030(const std::string &value);
		std::unique_ptr<IComponent> create4040(const std::string &value);
		std::unique_ptr<IComponent> create4069(const std::string &value);
		std::unique_ptr<IComponent> create4071(const std::string &value);
		std::unique_ptr<IComponent> create4081(const std::string &value);
		std::unique_ptr<IComponent> create4094(const std::string &value);
		std::unique_ptr<IComponent> create4514(const std::string &value);
		std::unique_ptr<IComponent> create4801(const std::string &value);

		std::unique_ptr<IComponent> createInput(const std::string &value);
		std::unique_ptr<IComponent> createOutput(const std::string &value);
		std::unique_ptr<IComponent> createClock(const std::string &value);
		std::unique_ptr<IComponent> createTrue(const std::string &value);
		std::unique_ptr<IComponent> createFalse(const std::string &value);
	}
}



#endif /* INCLUDE_FACTORY_HPP_ */
