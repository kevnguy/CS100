#ifndef POW_HPP
#define POW_HPP

#include "base.hpp"
#include "op.hpp"
#include <cmath>
#include "iterator.hpp"

class Iterator;	

class Pow : public Base {
   private:
        Base* op1;
        Base* op2;
   public:
        Pow(double , double );
        Pow(Base* , double );
        Pow(double , Base*);
        Pow(Base* , Base*);

        virtual double evaluate();
        virtual std::string stringify();

	virtual Iterator* create_iterator() { return new BinaryIterator(this); }
	virtual Base* get_left() { return op1; }
	virtual Base* get_right() { return op2; }
	void accept(CountVisitor* v) { v->visit_pow(); }
};

Pow::Pow(double v1, double v2) : Base(), op1(new Op(v1)), op2(new Op(v2)) {}

Pow::Pow(Base* v1, double v2) : Base(), op1(v1), op2(new Op(v2)) {}

Pow::Pow(double v1, Base* v2) : Base(), op1(new Op(v1)), op2(v2) {}

Pow::Pow(Base* v1, Base* v2) : Base(), op1(v1), op2(v2) {}

double Pow::evaluate() { return std::pow(op1->evaluate(),op2->evaluate());}

std::string Pow::stringify() { return "(" + op1->stringify() + "**" + op2->stringify() + ")"; }

#endif
