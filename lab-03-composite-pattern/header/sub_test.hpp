#ifndef SUB_TEST_HPP
#define SUB_TEST_HPP 

#include "gtest/gtest.h"

#include "mult.hpp"
#include "div.hpp"
#include "add.hpp"
#include "pow.hpp"
#include "sub.hpp"

TEST(SubTest, classes) {
     Base* newA = new Add(9.0,1.0);
     Base* newP = new Pow(newA,2);
     Base* newS = new Sub(newP,10);
     Base* newD = new Div(4,2);
     Mult* test = new Mult(newS, newD);
     EXPECT_EQ(test->evaluate(), 180);
     EXPECT_EQ(test->stringify(), "((((9.000000 + 1.000000)**2.000000) - 10.000000) * (4.000000 / 2.000000))");
 }

TEST(SubTest, positive) {
	Sub* newS = new Sub(2000, 100);
	Sub* test = new Sub(newS, 5);
	EXPECT_EQ(test->evaluate(), 1895.000000);
	EXPECT_EQ(test->stringify(), "((2000.000000 - 100.000000) - 5.000000)");
}

TEST(SubTest, negative) {
	Sub* newS = new Sub(-2000, -100);
	Sub* test = new Sub(newS, -5);
	EXPECT_EQ(test->evaluate(), -1895.000000);
	EXPECT_EQ(test->stringify(), "((-2000.000000 - -100.000000) - -5.000000)");
}

TEST(SubTest, posneg) {
	Sub* newS = new Sub(2000, -100);
	Sub* test = new Sub(newS, 5);
	EXPECT_EQ(test->evaluate(), 2095.000000);
	EXPECT_EQ(test->stringify(), "((2000.000000 - -100.000000) - 5.000000)");
}
#endif






