/*
 ** EPITECH PROJECT, 2019
 ** OOP_nanotekspice_2018
 ** File description: Created on: 30 janv. 2019
 ** Component2716.hpp
 */

#ifndef SRC_COMPONENT_CHIPSET_COMPONENT2716_HPP_
#define SRC_COMPONENT_CHIPSET_COMPONENT2716_HPP_

#include "Component.hpp"

namespace nts {

class Component2716: public Component {
	public:
		Component2716(const std::string& name);
		Component2716(const std::string& name, const std::string &fileName);
		virtual ~Component2716();
};

} /* namespace nts */

#endif /* SRC_COMPONENT_CHIPSET_COMPONENT2716_HPP_ */
