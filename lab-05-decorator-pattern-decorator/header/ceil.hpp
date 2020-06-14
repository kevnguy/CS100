#ifndef CEIL_HPP
#define CEIL_HPP

#include "decorator.hpp"

class Ceil : public Decorator {
   public:
	Ceil(Base* a) : Decorator(a) {}
        double evaluate() {
		return std::ceil(decoratedBase->evaluate());	
	} 
};
#endif
