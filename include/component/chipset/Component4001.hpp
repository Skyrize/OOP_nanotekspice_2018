/*
 ** EPITECH PROJECT, 2019
 ** OOP_nanotekspice_2018
 ** File description: Created on: 30 janv. 2019
 ** Component4001.hpp
 */

#ifndef SRC_COMPONENT_CHIPSET_COMPONENT4001_HPP_
#define SRC_COMPONENT_CHIPSET_COMPONENT4001_HPP_

#include "Component.hpp"

namespace nts {

class Component4001: public Component {
	public:
		Component4001(const std::string& name);
		virtual ~Component4001();
};

} /* namespace nts */

#endif /* SRC_COMPONENT_CHIPSET_COMPONENT4001_HPP_ */
