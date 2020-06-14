#ifndef CEIL_HPP
#define CEIL_HPP

#include "decorator.hpp"
#include "visitor.hpp"

class Ceil : public Decorator {
   public:
	Ceil(Base* a) : Decorator(a) {}
        double evaluate() {
		return std::ceil(decoratedBase->evaluate());	
	}
	Iterator* create_iterator() { return new UnaryIterator(this); } 
	Base* get_left() { return decoratedBase; }
        Base* get_right() { return 0; }
	void accept(CountVisitor* v) { v->visit_ceil(); } 
};
#endif
