
#ifndef TRUNC_TEST_HPP
#define TRUNC_TEST_HPP 

#include "gtest/gtest.h"

#include "mult.hpp"
#include "div.hpp"
#include "sub.hpp"
#include "pow.hpp"
#include "add.hpp"
#include "abs.hpp"
#include "trunc.hpp"
#include "paren.hpp"
#include "ceil.hpp"
#include "floor.hpp"

TEST(TruncTest, simple) {
	Base* PnewA = new Trunc(new Add(9.0,1.0));
	Base* PnewP = new Trunc(new Pow(PnewA,2));
	Base* PnewS = new Trunc(new Sub(PnewP,10));
	Base* PnewD = new Trunc(new Div(4,2));
	Base* Ptest = new Trunc(new Mult(PnewS, PnewD));
	EXPECT_EQ(Ptest->evaluate(), 180);
	EXPECT_EQ(Ptest->stringify(), "180.000000");
}
TEST(TruncTest, simpleZero) {
     Base* test = new Trunc(new Op(0));
     EXPECT_EQ(test->evaluate(), 0);
     EXPECT_EQ(test->stringify(), "0.000000");
}

TEST(TruncTest, classes) {
     Base* CeilAdd = new Ceil(new Add(2.5,1));
     Base* ParenTruncPow = new Paren(new Trunc(new Pow(CeilAdd,2)));
     Base* AbsSub = new Abs(new Sub(ParenTruncPow,800));
     Base* FloorAbsDiv = new Floor(new Abs(new Div(4.5,-2.2)));
     Base* test = new Paren(new Mult(AbsSub, FloorAbsDiv));

     EXPECT_EQ(test->evaluate(), 1568);
     EXPECT_EQ(test->stringify(), "((((16.000000) - 800.000000) * (4.500000 / -2.200000)))");
}

#endif
