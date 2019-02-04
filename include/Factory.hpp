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
		IComponent *createComponent(std::string &type, const std::string &value);

		IComponent *create2716(const std::string &value);
		IComponent *create4001(const std::string &value);
		IComponent *create4008(const std::string &value);
		IComponent *create4011(const std::string &value);
		IComponent *create4013(const std::string &value);
		IComponent *create4017(const std::string &value);
		IComponent *create4030(const std::string &value);
		IComponent *create4040(const std::string &value);
		IComponent *create4069(const std::string &value);
		IComponent *create4071(const std::string &value);
		IComponent *create4081(const std::string &value);
		IComponent *create4094(const std::string &value);
		IComponent *create4514(const std::string &value);
		IComponent *create4801(const std::string &value);

		std::vector<std::string> getDefaultValue(const std::string &value);

		IComponent *createInput(const std::string &value);
		IComponent *createOutput(const std::string &value);
		IComponent *createClock(const std::string &value);
		IComponent *createTrue(const std::string &value);
		IComponent *createFalse(const std::string &value);
	}
}



#endif /* INCLUDE_FACTORY_HPP_ */
