/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description:
** Circuit
*/

#ifndef CIRCUIT_HPP_
#define CIRCUIT_HPP_

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
            std::vector<IComponent *> getInputs() const { return _inputs; };
            std::vector<IComponent *> getOutputs() const { return _outputs; };
            std::vector<IComponent *> getComponents() const { return _components; };
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
