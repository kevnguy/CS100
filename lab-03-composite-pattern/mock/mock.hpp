#ifndef MOCK_HPP
#define MOCK_HPP

#include "../header/base.hpp"

class SevenAddMock: public Base {
    public:
        SevenAddMock() { };

        virtual double evaluate() { return 7; }
        virtual string stringify() { return "1.25 + 5.75"; }
};

class NegFiveSubMock: public Base {
    public:
        NegFiveSubMock() { };

        virtual double evaluate() { return -5; }
        virtual string stringify() { return "10 - 5"; }
};

class FourPowMock: public Base {
    public:
        FourPowMock() { };

        virtual double evaluate() { return 4; }
        virtual string stringify() { return "2**2"; }
};

#endif
