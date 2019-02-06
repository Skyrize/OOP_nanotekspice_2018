/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description:
** CommandLineInterpreter
*/

#ifndef COMMANDLINEINTERPRETER_HPP_
#define COMMANDLINEINTERPRETER_HPP_

#include "nts.hpp"
#include "Circuit.hpp"
#include <map>

namespace nts {

    class CommandLineInterpreter {

        using methodPointer_t = void (nts::CommandLineInterpreter::*)(Circuit *) const;

        public:
            CommandLineInterpreter();
            virtual ~CommandLineInterpreter() = default;
            void start(Circuit *circuit);
            void my_exit(Circuit *circuit) const;
            void display(Circuit *circuit) const;                                                                                                                                              
            void setInputValue(Circuit *circuit) const;
            void simulate(Circuit *circuit) const;
            void loop(Circuit *circuit) const;
            void dump(Circuit *circuit) const;
            
        private:
            void getLine();
            std::string _cmd;
            std::map<std::string, methodPointer_t> _map;

    };

}

#endif /* !COMMANDLINEINTERPRETER_HPP_ */
