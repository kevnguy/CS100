#ifndef DIV_TEST_HPP
#define DIV_TEST_HPP 

#include "gtest/gtest.h"

#include "mult.hpp"
#include "div.hpp"
#include "add.hpp"
#include "sub.hpp"
#include "pow.hpp"


TEST(DivTest, classes) {
     Base* newA = new Add(5.0,1.0);
     Base* newP = new Pow(newA,2);
     Base* newS = new Sub(newP,-10);
     Base* newD = new Div(8,4);
     Mult* test = new Mult(newS, newD);
     EXPECT_EQ(test->evaluate(), 92);
     EXPECT_EQ(test->stringify(), "((((5.000000 + 1.000000)**2.000000) - -10.000000) * (8.000000 / 4.000000))");
}

TEST(DivTest, oneOp) {	
    Div* newD = new Div(64,8);
    Div* test = new Div(newD, 1);
    EXPECT_EQ(test->evaluate(), 8);
    EXPECT_EQ(test->stringify(), "((64.000000 / 8.000000) / 1.000000)");
}

TEST(DivTest, OpZero) {
    Div* newD = new Div(1,4);
    Div* test = new Div(newD,2);
    EXPECT_EQ(test->evaluate(), 0.1250000);
    EXPECT_EQ(test->stringify(), "((1.000000 / 4.000000) / 2.000000)");
}

TEST(DivTest, OpNegNegNonZero) {
    Div* test = new Div(-1,-10);
    EXPECT_EQ(test->evaluate(), .1);
    EXPECT_EQ(test->stringify(), "(-1.000000 / -10.000000)");
}

TEST(DivTest, OpNegNonZeroLarge) {
    Div* test = new Div(-4500, 9);
    EXPECT_EQ(test->evaluate(), -500);
    EXPECT_EQ(test->stringify(), "(-4500.000000 / 9.000000)");
}
#endif
