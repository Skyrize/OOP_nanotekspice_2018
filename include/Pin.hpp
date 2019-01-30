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
            void setLink(const class Pin &link) { _link = link; };
            Tristate getState(void) { return _state; };
            const class Pin &getLink(void) { return _link; };
            void operator=(const class Pin &pin);
        
        private:
            Tristate _state = UNDEFINED;
            class Pin &_link;
            mode _mode = DEFAULT;

    };

}


#endif /* !PIN_HPP_ */
