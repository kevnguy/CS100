#ifndef SEVEN_OP_MOCK
#define SEVEN_OP_MOCK

#include "../header/base.hpp"

class SevenOpMock : public Base {
    public:
        SevenOpMock() { };

        virtual double evaluate() { return 7.5; }
        virtual std::string stringify() { return "7.5"; }
};

#endif //SEVEN_OP_MOCK
