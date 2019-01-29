/*
 ** EPITECH PROJECT, 2019
 ** OOP_nanotekspice_2018
 ** File description: Created on: 29 janv. 2019
 ** NanoError.hpp
 */

#ifndef SRC_NANOERROR_HPP_
#define SRC_NANOERROR_HPP_

#include <exception>
#include <string>

class NanoError: public std::exception {
	public:
		NanoError(std::string const &message);
		virtual ~NanoError();

        const char *what() const noexcept override { return _message.data();};

	protected:
        std::string _message;
};

#endif /* SRC_NANOERROR_HPP_ */
