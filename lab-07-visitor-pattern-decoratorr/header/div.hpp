#ifndef DIV_HPP
#define DIV_HPP

#include "base.hpp"
#include "op.hpp"
#include "iterator.hpp"

class Iterator;

class Div : public Base {
   private:
        Base* op1;
	Base* op2;
   public:
        Div(double , double );
	Div(Base* , double );
	Div(double , Base*);
	Div(Base* , Base*);

        virtual double evaluate();
        virtual std::string stringify();
	virtual Iterator* create_iterator();
	virtual Base* get_left();
	virtual Base* get_right();
	void accept(CountVisitor* v) { v->visit_div(); }

};

Div::Div(double v1, double v2) : Base(), op1(new Op(v1)), op2(new Op(v2)) {}

Div::Div(Base* v1, double v2) : Base(), op1(v1), op2(new Op(v2)) {}

Div::Div(double v1, Base* v2) : Base(), op1(new Op(v1)), op2(v2) {}

Div::Div(Base* v1, Base* v2) : Base(), op1(v1), op2(v2) {}

double Div::evaluate() { return op1->evaluate() / op2->evaluate(); }

std::string Div::stringify() { return "(" + op1->stringify() + " / " + op2->stringify()+ ")"; }

Iterator* Div::create_iterator() {
	return new BinaryIterator(this);
}
Base* Div::get_left(){
	return op1;
}
Base* Div::get_right() { 
	return op2;
}

#endif
