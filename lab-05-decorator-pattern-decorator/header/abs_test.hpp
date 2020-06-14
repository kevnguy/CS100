#ifndef ABS_TEST_HPP
#define ABS_TEST_HPP 

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

TEST(AbsTest, simple) {
     Base* newA = new Add(9.0,1.0);
     Base* newP = new Pow(newA,2);
     Base* DnewS = new Abs(new Sub(newP,190));
     Base* DnewD = new Abs(new Div(4,-2));
     Base* test = new Mult(DnewS, DnewD);
     EXPECT_EQ(test->evaluate(), 180);
     EXPECT_EQ(test->stringify(), "((((9.000000 + 1.000000)**2.000000) - 190.000000) * (4.000000 / -2.000000))"); 
}

TEST(AbsTest, simpleZero) {
     Base* test = new Abs(new Op(0));
     EXPECT_EQ(test->evaluate(), 0);
     EXPECT_EQ(test->stringify(), "0.000000");
}

TEST(AbsTest, classes) {
     Base* CnewA = new Ceil(new Add(9.5,1.2));
     Base* PTnewP = new Paren(new Trunc(new Pow(CnewA,2)));
     Base* AnewS = new Abs(new Sub(PTnewP,190));
     Base* FAnewD = new Floor(new Abs(new Div(4.5,-2.2)));
     Base* test = new Paren(new Mult(AnewS, FAnewD));
     EXPECT_EQ(test->evaluate(), 138);
     EXPECT_EQ(test->stringify(), "((((121.000000) - 190.000000) * (4.500000 / -2.200000)))");
}
#endif
