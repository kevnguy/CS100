#ifndef __OP_HPP__
#define __OP_HPP__

#include "base.hpp"
#include "iterator.hpp"
class Iterator;

class Op : public Base {
   private:
	double _value; 
   public:
        Op(double value) : Base(), _value(value) { }
        virtual double evaluate();
        virtual std::string stringify();
	virtual Iterator* create_iterator();
	virtual Base* get_left();
	virtual Base* get_right();
	void accept(CountVisitor* v) { v->visit_op(); }
};

double Op::evaluate() { return _value; }

std::string Op::stringify() { return std::to_string(_value); }

Iterator* Op::create_iterator() {
	return new NullIterator(this);
}
Base* Op::get_left() {
	return nullptr;
}
Base* Op::get_right(){
	return nullptr;
}

#endif //__OP_HPP__
