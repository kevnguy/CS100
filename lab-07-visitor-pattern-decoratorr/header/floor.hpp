#ifndef FLOOR_HPP
#define FLOOR_HPP

#include "decorator.hpp"
#include "visitor.hpp"

class Floor : public Decorator {
   public:
        Floor(Base* a) : Decorator(a) {}
        double evaluate() {
                return std::floor(decoratedBase->evaluate());
        }
	Iterator* create_iterator() { return new UnaryIterator(this); }
	Base* get_left() { return decoratedBase; }
        Base* get_right() { return 0; } 
	void accept(CountVisitor* v) { v->visit_floor(); } 
};
#endif
