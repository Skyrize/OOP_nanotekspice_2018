/*
 ** EPITECH PROJECT, 2019
 ** OOP_nanotekspice_2018
 ** File description: Created on: 30 janv. 2019
 ** Component4011.hpp
 */

#ifndef SRC_COMPONENT_CHIPSET_COMPONENT4011_HPP_
#define SRC_COMPONENT_CHIPSET_COMPONENT4011_HPP_

#include "Component.hpp"

namespace nts {

class Component4011: public Component {
	public:
		Component4011(const std::string& name);
		virtual ~Component4011();
};

} /* namespace nts */

#endif /* SRC_COMPONENT_CHIPSET_COMPONENT4011_HPP_ */
