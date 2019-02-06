/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description:
** Pin
*/

#ifndef PIN_HPP_
#define PIN_HPP_

#include "nts.hpp"
#include <functional>
#include <utility>


namespace nts {

    using mTristate = std::function<Tristate()>;
    class Pin {
        public:
            Pin(mTristate compute, Tristate state = UNDEFINED);
            virtual ~Pin();
            void setState(Tristate state);
            void setLink(class Pin *link);
            Tristate getState(void);
            Pin *getLink(void);
            void operator=(const class Pin &pin);
            bool isLinked(void);
            Tristate compute();

        private:
            Tristate _state = UNDEFINED;
            class Pin *_link = nullptr;
            bool _isLinked = false;
            mTristate _ptr;

    };
}

#endif /* !PIN_HPP_ */
