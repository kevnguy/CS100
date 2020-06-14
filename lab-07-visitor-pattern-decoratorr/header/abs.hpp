#ifndef ABS_HPP
#define ABS_HPP

#include "decorator.hpp"
#include "visitor.hpp"

class Abs : public Decorator {
    public:
	Abs(Base* baseTree) : Decorator(baseTree) {}
	double evaluate() { return std::abs(decoratedBase->evaluate()); }
	Iterator* create_iterator() { return new UnaryIterator(this); }
	Base* get_left() { return decoratedBase; }
	Base* get_right() { return 0; }
	void accept(CountVisitor* v) { v->visit_abs(); }

};

#endif
