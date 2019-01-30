/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description:
** Pin
*/

#ifndef PIN_HPP_
#define PIN_HPP_

#include "nts.hpp"

namespace nts {

    class Pin {
        public:
            typedef enum {
                DEFAULT,
                INPUT,
                OUTPUT
            } mode;
            Pin();
            virtual ~Pin() = default;
            void setState(Tristate state) { _state = state; };
            void setLink(IComponent *link) { _link = link; };
            Tristate getState(void) { return _state; };
            IComponent *getLink(void) { return _link; };
        
        private:
            Tristate _state = UNDEFINED;
            IComponent *_link = nullptr;
            mode _mode = DEFAULT;

    };

}


#endif /* !PIN_HPP_ */
