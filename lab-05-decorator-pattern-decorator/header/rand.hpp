#ifndef RAND_HPP
#define RAND_HPP

#include "base.hpp"
#include <ctime>
#include <algorithm>

class Rand : public Base {
   private:
	double _value;
   public:
        Rand() : Base(), _value(std::rand() % 100 ) { }
        virtual double evaluate();
        virtual std::string stringify();
};

double Rand::evaluate() { return _value; }

std::string Rand::stringify() { return std::to_string(_value); }

#endif 
