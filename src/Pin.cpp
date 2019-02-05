/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description: Created on: 5 févr. 2019
** Pin.cpp
*/

#include "Pin.hpp"

nts::Pin::Pin()
{
}

nts::Pin::~Pin()
{
}

void nts::Pin::setState(Tristate state)
{
	_state = state;
}

void nts::Pin::setLink(const class Pin& link)
{
	_link = link._link;
}

nts::Tristate nts::Pin::getState(void)
{
	return _state;
}

nts::Pin* nts::Pin::getLink(void)
{
	return _link;
}

void nts::Pin::operator =(const class Pin& pin)
{
	this->_state = pin._state;
	this->_link = pin._link;
	this->_mode = pin._mode;
}




