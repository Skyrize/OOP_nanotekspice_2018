/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description: Created on: 5 févr. 2019
** Pin.cpp
*/

#include "Pin.hpp"

nts::Pin::Pin(mTristate compute, Tristate state)
{
	this->_state = state;
    this->_ptr = compute;
}

nts::Pin::~Pin()
{
}

void nts::Pin::setState(Tristate state)
{
	_state = state;
}

void nts::Pin::setLink(class Pin *link)
{
	_link = link;
	link->_isLinked = true;
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

bool nts::Pin::isLinked(void)
{
	return this->_isLinked;
}