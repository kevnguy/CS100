#ifndef SUB_HPP
#define SUB_HPP

#include "base.hpp"
#include "op.hpp"
#include "iterator.hpp"

class Iterator;

class Sub : public Base {
   private:
        Base* op1;
        Base* op2;
   public:
        Sub(double , double );
        Sub(Base* , double );
        Sub(double , Base*);
        Sub(Base* , Base*);

        virtual double evaluate();
        virtual std::string stringify();
	virtual Iterator* create_iterator();
	virtual Base* get_left();
	virtual Base* get_right();
	void accept(CountVisitor* v) { v->visit_sub(); }

};

Sub::Sub(double v1, double v2) : Base(), op1(new Op(v1)), op2(new Op(v2)) {}

Sub::Sub(Base* v1, double v2) : Base(), op1(v1), op2(new Op(v2)) {}

Sub::Sub(double v1, Base* v2) : Base(), op1(new Op(v1)), op2(v2) {}

Sub::Sub(Base* v1, Base* v2) : Base(), op1(v1), op2(v2) {}

double Sub::evaluate() { return op1->evaluate() - op2->evaluate(); }

std::string Sub::stringify() { return "(" + op1->stringify() + " - " + op2->stringify() + ")"; }

Iterator* Sub::create_iterator(){
	return new BinaryIterator(this);
}

Base* Sub::get_left(){
	return op1;
}
Base* Sub::get_right(){
	return op2;
}
#endif
