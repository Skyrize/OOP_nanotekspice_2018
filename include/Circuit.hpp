/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description:
** Circuit
*/

#ifndef CIRCUIT_HPP_
#define CIRCUIT_HPP_

#include <memory>
#include "nts.hpp"

namespace nts {
    class Circuit {
        public:
            Circuit();
            virtual ~Circuit() = default;
            void display() const;
            void setInputValue(const std::string &name, size_t value);
            void run();
            void loop();
            void dump() const;
            void pushComponent(IComponent *component);
            void pushInput(IComponent *component);
            void pushOutput(IComponent *component);

        private:
            std::vector<IComponent *> _components;
            std::vector<IComponent *> _inputs;
            std::vector<IComponent *> _outputs;
            
    };
}

#endif /* !CIRCUIT_HPP_ */
