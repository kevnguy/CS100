#ifndef HUNDRED_OP_MOCK
#define HUNDRED_OP_MOCK

#include "../header/base.hpp"

class HundredOpMock: public Base {
    public:
        HundredOpMock() { };

        virtual double evaluate() { return 100; }
        virtual string stringify() { return "100"; }
};

#endif
