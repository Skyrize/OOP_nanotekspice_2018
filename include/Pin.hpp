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
            Pin(Tristate state = UNDEFINED);
            virtual ~Pin();
            void setState(Tristate state);
            void setLink(class Pin *link);
            Tristate getState(void);
            Pin *getLink(void);
            void operator=(const class Pin &pin);
            bool isLinked(void);
        
        private:
            Tristate _state = UNDEFINED;
            class Pin *_link = nullptr;
            mode _mode = DEFAULT;
            bool _isLinked = false;

    };
}

#endif /* !PIN_HPP_ */
