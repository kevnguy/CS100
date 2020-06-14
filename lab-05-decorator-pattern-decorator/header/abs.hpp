#ifndef ABS_HPP
#define ABS_HPP

#include "decorator.hpp"

class Abs : public Decorator {
    public:
	Abs(Base* baseTree) : Decorator(baseTree) {}
	double evaluate() { return std::abs(decoratedBase->evaluate()); }
	//std::string stringify() { return decoratedBase->stringify(); }
};

#endif
