/*
 ** EPITECH PROJECT, 2019
 ** OOP_nanotekspice_2018
 ** File description: Created on: 30 janv. 2019
 ** Input.hpp
 */

#ifndef SRC_INPUT_HPP_
#define SRC_INPUT_HPP_

#include "Component.hpp"

namespace nts {

class Input: public Component {
	public:
		Input(const std::string &name, Tristate value = Tristate::UNDEFINED);
		virtual ~Input();
};

} /* namespace nts */

#endif /* SRC_INPUT_HPP_ */
