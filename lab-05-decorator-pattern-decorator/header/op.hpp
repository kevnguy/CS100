#ifndef __OP_HPP__
#define __OP_HPP__

#include "base.hpp"

class Op : public Base {
   private:
	double _value; 
   public:
        Op(double value) : Base(), _value(value) { }
        virtual double evaluate();
        virtual std::string stringify();
};

double Op::evaluate() { return _value; }

std::string Op::stringify() { return std::to_string(_value); }

#endif //__OP_HPP__
