#ifndef PAREN_hpp
#define PAREN_hpp

#include "decorator.hpp"
#include "visitor.hpp"

class Paren : public Decorator {
    public:
	Paren(Base* baseTree): Decorator(baseTree) {}
	std::string stringify() { return "(" + decoratedBase->stringify() + ")"; }
	Iterator* create_iterator() { return new UnaryIterator(this); }
	Base* get_left() { return decoratedBase; }
        Base* get_right() { return 0; } 
	void accept(CountVisitor* v) { v->visit_paren(); } 
};

#endif
