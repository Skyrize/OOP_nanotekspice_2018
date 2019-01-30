/*
 ** EPITECH PROJECT, 2019
 ** OOP_nanotekspice_2018
 ** File description: Created on: 30 janv. 2019
 ** Output.hpp
 */

#ifndef SRC_OUTPUT_HPP_
#define SRC_OUTPUT_HPP_

#include "Component.hpp"

namespace nts {

class Output: public Component {
	public:
		Output(const std::string &name);
		virtual ~Output();
};

} /* namespace nts */

#endif /* SRC_OUTPUT_HPP_ */
