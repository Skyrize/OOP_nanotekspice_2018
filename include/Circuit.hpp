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
            std::vector<std::unique_ptr<IComponent> > getInputs() const { return _inputs; };
            std::vector<std::unique_ptr<IComponent> > getOutputs() const { return _outputs; };
            std::vector<std::unique_ptr<IComponent> > getComponents() const { return _components; };
            void pushComponent(std::unique_ptr<IComponent> &component);
            void pushInput(std::unique_ptr<IComponent> &component);
            void pushOutput(std::unique_ptr<IComponent> &component);

        private:
            std::vector<std::unique_ptr<IComponent> > _components;
            std::vector<std::unique_ptr<IComponent> > _inputs;
            std::vector<std::unique_ptr<IComponent> > _outputs;
            
    };
}

#endif /* !CIRCUIT_HPP_ */
