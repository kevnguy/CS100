#ifndef TRUNC_HPP
#define TRUNC_HPP

#include "decorator.hpp"
#include "visitor.hpp"

class Trunc : public Decorator {
   public:
        Trunc(Base* a) : Decorator(a) {}
        std::string stringify() {
                return std::to_string(decoratedBase->evaluate());
        }
	Iterator* create_iterator() { return new UnaryIterator(this); }
	Base* get_left() { return decoratedBase; }
        Base* get_right() { return 0; } 
	void accept(CountVisitor* v) { v->visit_trunc(); } 
};
#endif
