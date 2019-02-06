/*
 ** EPITECH PROJECT, 2019
 ** OOP_nanotekspice_2018
 ** File description: Created on: 30 janv. 2019
 ** Component.hpp
 */

#ifndef SRC_COMPONENT_CHIPSET_COMPONENT_HPP_
#define SRC_COMPONENT_CHIPSET_COMPONENT_HPP_

#include "nts.hpp"
#include "Pin.hpp"
#include "Gates.hpp"

namespace nts {

class Component: public IComponent {
	protected:
		std::vector<Pin *> _pins;
		std::string _name;

	public:
		Component(const std::string &name);
		virtual ~Component();

        virtual nts::Tristate compute(size_t pin = 1);
        virtual void setLink(size_t pin, nts::IComponent &other, size_t otherPin);
        virtual void dump() const;
        virtual class Pin *getPin(const size_t &pin);


		std::string getName() const
		{
			return _name;
		}

		void setName(const std::string& name)
		{
			this->_name = name;
		}

};

} /* namespace nts */

#endif /* SRC_COMPONENT_CHIPSET_COMPONENT_HPP_ */
