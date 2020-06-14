#ifndef MULT_HPP
#define MULT_HPP

#include "base.hpp"
#include "op.hpp"

class Mult : public Base {
   private:
        Base* op1;
	Base* op2;
   public:
        Mult(double , double );
	Mult(Base* , double );
	Mult(double , Base*);
	Mult(Base* , Base*);

        virtual double evaluate();
        virtual std::string stringify();
};

Mult::Mult(double v1, double v2) : Base(), op1(new Op(v1)), op2(new Op(v2)) {}

Mult::Mult(Base* v1, double v2) : Base(), op1(v1), op2(new Op(v2)) {}

Mult::Mult(double v1, Base* v2) : Base(), op1(new Op(v1)), op2(v2) {}

Mult::Mult(Base* v1, Base* v2) : Base(), op1(v1), op2(v2) {}

double Mult::evaluate() { return op1->evaluate() * op2->evaluate(); }

std::string Mult::stringify() { return "(" +  op1->stringify() + " * " + op2->stringify() + ")"; }

#endif
