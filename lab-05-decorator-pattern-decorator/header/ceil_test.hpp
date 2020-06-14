#ifndef CEIL_TEST_HPP
#define CEIL_TEST_HPP 

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

TEST(CeilTest, simple) {
     Base* A = new Ceil(new Add(15, 14.6));//30
     Base* S = new Ceil(new Sub(15.6, 15));//1
     Base* M = new Ceil(new Mult(1.3, 2));//3
     Base* D = new Ceil(new Div(8, 5));//2
     Base* P = new Ceil(new Pow(4, 0.5));//2
     Base* temp = new Add(A, S);//31
     Base* temp2 = new Add(D, P);//4
     Base* temp3 = new Add(temp, temp2);//35
     Base* test = new Ceil(new Div(temp3, M));//12
     EXPECT_EQ(A->evaluate(), 30);
     EXPECT_EQ(S->evaluate(), 1);
     EXPECT_EQ(M->evaluate(), 3);
     EXPECT_EQ(D->evaluate(), 2);
     EXPECT_EQ(P->evaluate(), 2);
     EXPECT_EQ(temp->evaluate(), 31);
     EXPECT_EQ(temp2->evaluate(), 4);
     EXPECT_EQ(temp3->evaluate(), 35);
     EXPECT_EQ(test->evaluate(), 12);
     EXPECT_EQ(test->stringify(), "((((15.000000 + 14.600000) + (15.600000 - 15.000000)) + ((8.000000 / 5.000000) + (4.000000**0.500000))) / (1.300000 * 2.000000))"); 
}

TEST(CeilTest, simpleZero) {
     Base* test = new Ceil(new Op(0));
     EXPECT_EQ(test->evaluate(), 0);
     EXPECT_EQ(test->stringify(), "0.000000");
}

TEST(CeilTest, classes) {
     Base* CeilAdd = new Ceil(new Add(2.5,1));
     Base* ParenTruncPow = new Paren(new Trunc(new Pow(CeilAdd,2)));
     Base* AbsSub = new Abs(new Sub(ParenTruncPow,800));
     Base* AbsDiv = new Floor(new Abs(new Div(4.5,-2.2)));
     Base* test = new Paren(new Mult(AbsSub, AbsDiv));

     EXPECT_EQ(test->evaluate(), 1568);
     EXPECT_EQ(test->stringify(), "((((16.000000) - 800.000000) * (4.500000 / -2.200000)))");
}
#endif
