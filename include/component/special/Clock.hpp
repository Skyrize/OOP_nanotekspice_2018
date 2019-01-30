/*
 ** EPITECH PROJECT, 2019
 ** OOP_nanotekspice_2018
 ** File description: Created on: 30 janv. 2019
 ** Clock.hpp
 */

#ifndef SRC_CLOCK_HPP_
#define SRC_CLOCK_HPP_

#include "Input.hpp"

namespace nts {

class Clock: public Input {
	public:
		Clock();
		virtual ~Clock();
};

} /* namespace nts */

#endif /* SRC_CLOCK_HPP_ */
