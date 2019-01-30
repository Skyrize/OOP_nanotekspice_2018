/*
 ** EPITECH PROJECT, 2019
 ** OOP_nanotekspice_2018
 ** File description: Created on: 30 janv. 2019
 ** Component4030.hpp
 */

#ifndef SRC_COMPONENT_CHIPSET_COMPONENT4030_HPP_
#define SRC_COMPONENT_CHIPSET_COMPONENT4030_HPP_

#include "Component.hpp"

namespace nts {

class Component4030: public Component {
	public:
		Component4030(const std::string& name);
		virtual ~Component4030();
};

} /* namespace nts */

#endif /* SRC_COMPONENT_CHIPSET_COMPONENT4030_HPP_ */
