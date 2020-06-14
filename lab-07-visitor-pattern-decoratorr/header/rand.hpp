#ifndef RAND_HPP
#define RAND_HPP

#include "base.hpp"
#include <ctime>
#include <algorithm>

#include "iterator.hpp"

class Iterator;

class Rand : public Base {
   private:
	double _value;
   public:
        Rand() : Base(), _value(std::rand() % 100 ) { }
        virtual double evaluate();
        virtual std::string stringify();
	virtual Iterator* create_iterator() { return new NullIterator(this); }
	virtual Base* get_left() { return nullptr; }                                                                                                            
	virtual Base* get_right() { return nullptr; }
	void accept(CountVisitor* v) { v->visit_rand(); }
};

double Rand::evaluate() { return _value; }

std::string Rand::stringify() { return std::to_string(_value); }

#endif 
