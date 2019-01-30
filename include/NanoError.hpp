/*
 ** EPITECH PROJECT, 2019
 ** OOP_nanotekspice_2018
 ** File description: Created on: 29 janv. 2019
 ** NanoError.hpp
 */

#ifndef SRC_NANOERROR_HPP_
#define SRC_NANOERROR_HPP_

#include "nts.hpp"
#include <exception>
#include <string>

namespace nts {

    class NanoError: public std::exception {
        public:
            NanoError(std::string const &message);
            virtual ~NanoError();

            const char *what() const noexcept override { return _message.data();};

        protected:
            std::string _message;
    };

    class CircuitFileError : public NanoError {
        public:
            CircuitFileError(std::string const &message = "The circuit file includes one or several lexical or syntactic errors.");
    };

    class ComponentTypeError : public NanoError {
        public:
            ComponentTypeError(std::string const &message = "A component type is unknown.");
    };

    class ComponentNameError : public NanoError {
        public:
            ComponentNameError(std::string const &message = "A component name is unknown.");
    };

    class UnexistingPinError : public NanoError {
        public:
            UnexistingPinError(std::string const &message = "A requested pin does not exist.");
    };

    class RedefinedComponentError : public NanoError {
        public:
            RedefinedComponentError(std::string const &message = "Several components share the same name.");
    };

    class UnlinkedOutputError : public NanoError {
        public:
            UnlinkedOutputError(std::string const &message = "One or several outputs are not linked.");
    };

    class UnprovidedInputError : public NanoError {
        public:
            UnprovidedInputError(std::string const &message = "One or several input values were not provided on the command line.");
    };

    class UnknowInputError : public NanoError {
        public:
            UnknowInputError(std::string const &message = "A provided input is unknown.");
    };

    class MissingChipsetSectionError : public NanoError {
        public:
            MissingChipsetSectionError(std::string const &message = "No chipset section.");
    };

    class MissingLinksSectionError : public NanoError {
        public:
            MissingLinksSectionError(std::string const &message = "No links section.");
    };

    class UsageError : public NanoError {
        public:
    		UsageError(std::string const &message = "Usage: ./nanotekspice [circuit_file.nts] [component=value ...]");
    };

}

#endif /* SRC_NANOERROR_HPP_ */
