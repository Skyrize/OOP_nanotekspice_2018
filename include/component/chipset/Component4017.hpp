/*
 ** EPITECH PROJECT, 2019
 ** OOP_nanotekspice_2018
 ** File description: Created on: 30 janv. 2019
 ** Component4017.hpp
 */

#ifndef SRC_COMPONENT_CHIPSET_COMPONENT4017_HPP_
#define SRC_COMPONENT_CHIPSET_COMPONENT4017_HPP_

#include "Component.hpp"

namespace nts {

class Component4017: public Component {
	public:
		Component4017(const std::string& name);
		virtual ~Component4017();
        Tristate getPreviousCp0() const { return _cp0; };
        Tristate getPreviousCp1() const { return _cp1; };
        void setPreviousCp0(Tristate state) { _cp0 = state; };
        void setPreviousCp1(Tristate state) { _cp1 = state; };
        short getSequence() const { return _sequence; };
        void setSequence(short sequence) { _sequence = sequence; };

    private:
        short _sequence = 0;
        Tristate _cp0 = UNDEFINED;
        Tristate _cp1 = UNDEFINED;
};

} /* namespace nts */

#endif /* SRC_COMPONENT_CHIPSET_COMPONENT4017_HPP_ */
