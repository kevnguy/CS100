#ifndef ADD_HPP
#define ADD_HPP

#include "base.hpp"
#include "op.hpp"

class Add : public Base {
   private:
        Base* op1;
        Base* op2;
   public:
        Add(double , double );
        Add(Base* , double );
        Add(double , Base*);
        Add(Base* , Base*);

        virtual double evaluate();
        virtual std::string stringify();
};

Add::Add(double v1, double v2) : Base(), op1(new Op(v1)), op2(new Op(v2)) {}

Add::Add(Base* v1, double v2) : Base(), op1(v1), op2(new Op(v2)) {}

Add::Add(double v1, Base* v2) : Base(), op1(new Op(v1)), op2(v2) {}

Add::Add(Base* v1, Base* v2) : Base(), op1(v1), op2(v2) {}

double Add::evaluate() { return op1->evaluate() + op2->evaluate(); }

std::string Add::stringify() { return "(" + op1->stringify() + " + " + op2->stringify() + ")"; }

#endif

