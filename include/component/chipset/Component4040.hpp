/*
 ** EPITECH PROJECT, 2019
 ** OOP_nanotekspice_2018
 ** File description: Created on: 30 janv. 2019
 ** Component4040.hpp
 */

#ifndef SRC_COMPONENT_CHIPSET_COMPONENT4040_HPP_
#define SRC_COMPONENT_CHIPSET_COMPONENT4040_HPP_

#include "Component.hpp"

namespace nts {

class Component4040: public Component {
	protected:
		int memoryClock = 0;
		int openPin = 0;
		Tristate previousClockState = Tristate::UNDEFINED;
	public:
		Component4040(const std::string& name);
		virtual ~Component4040();
		void incrementMemoryClock();
		void resetMemoryClock();
		bool isClockStarting() {
			if (this->previousClockState == Tristate::UNDEFINED)
				return true;
			return false;
			};

		Tristate getOutputStatus(size_t outputPin);
		void setPreviousClockState(Tristate state);
		Tristate getPreviousClockState();
};

} /* namespace nts */

#endif /* SRC_COMPONENT_CHIPSET_COMPONENT4040_HPP_ */
