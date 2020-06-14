#ifndef PAREN_hpp
#define PAREN_hpp

#include "decorator.hpp"

class Paren : public Decorator {
    public:
	Paren(Base* baseTree): Decorator(baseTree) {}
	std::string stringify() { return "(" + decoratedBase->stringify() + ")"; }
};

#endif
