#ifndef FLOOR_HPP
#define FLOOR_HPP

#include "decorator.hpp"

class Floor : public Decorator {
   public:
        Floor(Base* a) : Decorator(a) {}
        double evaluate() {
                return std::floor(decoratedBase->evaluate());
        }
};
#endif
