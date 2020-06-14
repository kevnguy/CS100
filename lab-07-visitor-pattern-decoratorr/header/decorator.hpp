#ifndef DECORATOR_HPP
#define DECORATOR_HPP

#include "base.hpp"
#include<string>
#include<cmath>

class Decorator : public Base {
    protected: 
	Base* decoratedBase;
    public:
	Decorator(Base* decoration): decoratedBase(decoration)  {};
        double evaluate() { return decoratedBase->evaluate(); }
        std::string stringify() { return decoratedBase->stringify(); }
};
#endif
