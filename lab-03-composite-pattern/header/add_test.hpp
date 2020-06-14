#ifndef ADD_TEST_HPP
#define ADD_TEST_HPP 

#include "gtest/gtest.h"

#include "mult.hpp"
#include "div.hpp"
#include "sub.hpp"
#include "pow.hpp"
#include "add.hpp"

TEST(AddTest, classes) {
     Base* newA = new Add(9.0,1.0);
     Base* newP = new Pow(newA,2);
     Base* newS = new Sub(newP,10);
     Base* newD = new Div(4,2);
     Mult* test = new Mult(newS, newD);
     EXPECT_EQ(test->evaluate(), 180);
     EXPECT_EQ(test->stringify(), "((((9.000000 + 1.000000)**2.000000) - 10.000000) * (4.000000 / 2.000000))");
 }


TEST(AddTest, positive) {
	Add* newA = new Add(100, 2000);
	Add* test = new Add(newA, 5);
	EXPECT_EQ(test->evaluate(), 2105.000000);
	EXPECT_EQ(test->stringify(), "((100.000000 + 2000.000000) + 5.000000)");
}

TEST(AddTest, negative) {
	Add* newA = new Add(-100, -2000);
	Add* test = new Add(newA, -5);
	EXPECT_EQ(test->evaluate(), -2105.000000);
	EXPECT_EQ(test->stringify(), "((-100.000000 + -2000.000000) + -5.000000)");
}

TEST(AddTest, posneg) {
	Add* newA = new Add(-100, 2000);
	Add* test = new Add(newA, 5);
	EXPECT_EQ(test->evaluate(), 1905.000000);
	EXPECT_EQ(test->stringify(), "((-100.000000 + 2000.000000) + 5.000000)");
}

#endif

