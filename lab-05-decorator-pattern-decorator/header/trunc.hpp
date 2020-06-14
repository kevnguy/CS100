#ifndef TRUNC_HPP
#define TRUNC_HPP

#include "decorator.hpp"

class Trunc : public Decorator {
   public:
        Trunc(Base* a) : Decorator(a) {}
        std::string stringify() {
                return std::to_string(decoratedBase->evaluate());
        }
};
#endif
