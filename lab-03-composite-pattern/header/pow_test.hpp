#ifndef POW_TEST_HPP
#define POW_TEST_HPP 

#include "gtest/gtest.h"

#include "mult.hpp"
#include "div.hpp"
#include "add.hpp"
#include "sub.hpp"
#include "pow.hpp"

TEST(PowTest, classes) {
     Base* newA = new Add(9.0,1.0);
     Base* newP = new Pow(newA,2);
     Base* newS = new Sub(newP,10);
     Base* newD = new Div(4,2);
     Mult* test = new Mult(newS, newD);
     EXPECT_EQ(test->evaluate(), 180);
     EXPECT_EQ(test->stringify(), "((((9.000000 + 1.000000)**2.000000) - 10.000000) * (4.000000 / 2.000000))");
 }

TEST(PowTest, positive) {
	Pow* newP = new Pow(2, 3);
	Pow* test = new Pow(newP, 2);
	EXPECT_EQ(test->evaluate(), 64);
	EXPECT_EQ(test->stringify(), "((2.000000**3.000000)**2.000000)");//probably will have to fix this alongside sub and add
}

TEST(PowTest, negative) {
	Pow* newP = new Pow(-2, -2);
	Pow* test = new Pow(newP, 2);
	EXPECT_EQ(test->evaluate(), 0.0625);
	EXPECT_EQ(test->stringify(), "((-2.000000**-2.000000)**2.000000)");//probably will have to fix this alongside sub and add
}

#endif







