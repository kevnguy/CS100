#ifndef MULT_TEST_HPP
#define MULT_TEST_HPP 

#include "gtest/gtest.h"

#include "mult.hpp"
#include "div.hpp"
#include "add.hpp"
#include "sub.hpp"
#include "pow.hpp"


TEST(MultTest, classes) {
    Base* newA = new Add(1.0,1.0);
    Base* newP = new Pow(newA,2);
    Base* newS = new Sub(newP,-2);
    Base* newD = new Div(8,4);	
    Mult* test = new Mult(newS, newD);
    EXPECT_EQ(test->evaluate(), 12);
    EXPECT_EQ(test->stringify(), "((((1.000000 + 1.000000)**2.000000) - -2.000000) * (8.000000 / 4.000000))");
}


TEST(MultTest, oneOp) {	
    Base* newM = new Mult(8,8);
    Mult* test = new Mult(newM, 1);
    EXPECT_EQ(test->evaluate(), 64);
    EXPECT_EQ(test->stringify(), "((8.000000 * 8.000000) * 1.000000)");
}

TEST(MultTest, OpZero) {
    Mult* test = new Mult(0.0,1.0);
    EXPECT_EQ(test->evaluate(), 0);
    EXPECT_EQ(test->stringify(), "(0.000000 * 1.000000)");
}

TEST(MultTest, OpZero2) {
    Mult* test = new Mult(1.0,0.0);
    EXPECT_EQ(test->evaluate(), 0);
    EXPECT_EQ(test->stringify(), "(1.000000 * 0.000000)");
}

TEST(MultTest, OpNegNonZero) {
    Mult* test = new Mult(-568, 952);
    EXPECT_EQ(test->evaluate(), -540736);
    EXPECT_EQ(test->stringify(), "(-568.000000 * 952.000000)");
}
#endif
