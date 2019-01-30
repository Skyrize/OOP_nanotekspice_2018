/*
 ** EPITECH PROJECT, 2019
 ** OOP_nanotekspice_2018
 ** File description: Created on: 30 janv. 2019
 ** Component4013.hpp
 */

#ifndef SRC_COMPONENT_CHIPSET_COMPONENT4013_HPP_
#define SRC_COMPONENT_CHIPSET_COMPONENT4013_HPP_

#include "Component.hpp"

namespace nts {

class Component4013: public Component {
	public:
		Component4013(const std::string& name);
		virtual ~Component4013();
};

} /* namespace nts */

#endif /* SRC_COMPONENT_CHIPSET_COMPONENT4013_HPP_ */
