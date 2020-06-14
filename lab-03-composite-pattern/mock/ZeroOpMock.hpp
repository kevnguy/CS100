#ifndef ZERO_OP_MOCK
#define ZERO_OP_MOCK

#include "../header/base.hpp"

class ZeroOpMock: public Base {
    public:
        ZeroOpMock() { };

        virtual double evaluate() { return 0; }
        virtual string stringify() { return "0"; }
};

#endif
