#ifndef NEG_SEVEN_OP_MOCK
#define NEG_SEVEN_OP_MOCK

#include "../header/base.hpp"

class NegSevenOpMock: public Base {
    public:
       NegSevenOpMock() { };

        virtual double evaluate() { return -7.5; }
        virtual string stringify() { return "-7.5"; }
};

#endif
