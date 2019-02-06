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
            Pin() = default;
            virtual ~Pin() = default;
            void setState(Tristate state) { _state = state; };
            void setLink(class Pin *link) { _link = link; };
            Tristate getState(void) const { return _state; };
            class Pin *getLink(void) const { return _link; };
            void setMode(Pin::mode mode) {_mode = mode; };
            Pin::mode getMode(void) const { return _mode; };
            void setCompute(Tristate (*compute)()) {
                this->compute = compute;
            };
            void operator=(const class Pin *pin) {
                _state = pin->getState();
                _link = pin->getLink();
                _mode = pin->getMode();
            };
            Tristate (*compute)();

        private:
            Tristate _state = UNDEFINED;
            class Pin *_link;
            mode _mode = DEFAULT;

    };

}


#endif /* !PIN_HPP_ */
