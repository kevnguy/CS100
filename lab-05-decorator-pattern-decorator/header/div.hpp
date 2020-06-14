#ifndef DIV_HPP
#define DIV_HPP

#include "base.hpp"
#include "op.hpp"

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
};

Div::Div(double v1, double v2) : Base(), op1(new Op(v1)), op2(new Op(v2)) {}

Div::Div(Base* v1, double v2) : Base(), op1(v1), op2(new Op(v2)) {}

Div::Div(double v1, Base* v2) : Base(), op1(new Op(v1)), op2(v2) {}

Div::Div(Base* v1, Base* v2) : Base(), op1(v1), op2(v2) {}

double Div::evaluate() { return op1->evaluate() / op2->evaluate(); }

std::string Div::stringify() { return "(" + op1->stringify() + " / " + op2->stringify()+ ")"; }

#endif
