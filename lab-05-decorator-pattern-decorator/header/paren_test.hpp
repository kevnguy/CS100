#ifndef PAREN_TEST_HPP
#define PAREN_TEST_HPP 

#include "gtest/gtest.h"

#include "mult.hpp"
#include "div.hpp"
#include "sub.hpp"
#include "pow.hpp"
#include "add.hpp"
#include "abs.hpp"
#include "paren.hpp"
#include "trunc.hpp"
#include "ceil.hpp"
#include "floor.hpp"

TEST(ParenTest, classes) {
     Base* PnewA = new Paren(new Add(9.0,1.0));
     Base* FCnewP = new Floor(new Ceil(new Pow(PnewA,2)));
     Base* DnewS = new Abs(new Sub(FCnewP,190));
     Base* DnewD = new Abs(new Div(4,-2));
     Base* test = new Trunc(new Mult(DnewS, DnewD));
     EXPECT_EQ(test->evaluate(), 180);
     EXPECT_EQ(test->stringify(), "180.000000"); 
}

TEST(ParenTest, simple) { 
     Base* PnewA = new Paren(new Add(9.0,1.0));
     Base* PnewP = new Paren(new Pow(PnewA,2));
     Base* PnewS = new Paren(new Sub(PnewP,10));
     Base* PnewD = new Paren(new Div(4,2));
     Base* Ptest = new Paren(new Mult(PnewS, PnewD));
     EXPECT_EQ(Ptest->evaluate(), 180);
     EXPECT_EQ(Ptest->stringify(), "((((((((9.000000 + 1.000000))**2.000000)) - 10.000000)) * ((4.000000 / 2.000000))))");
}

TEST(ParenTest, zero) {
    Base* test = new Paren(new Op(0));
    EXPECT_EQ(test->evaluate(), 0);
    EXPECT_EQ(test->stringify(), "(0.000000)");
}

#endif
