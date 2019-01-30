/*
 ** EPITECH PROJECT, 2019
 ** OOP_nanotekspice_2018
 ** File description: Created on: 30 janv. 2019
 ** Component4801.hpp
 */

#ifndef SRC_COMPONENT_CHIPSET_COMPONENT4801_HPP_
#define SRC_COMPONENT_CHIPSET_COMPONENT4801_HPP_

#include "Component.hpp"

namespace nts {

class Component4801: public Component {
	public:
		Component4801(const std::string& name);
		virtual ~Component4801();
};

} /* namespace nts */

#endif /* SRC_COMPONENT_CHIPSET_COMPONENT4801_HPP_ */
