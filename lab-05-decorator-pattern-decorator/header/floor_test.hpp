#ifndef FLOOR_TEST_HPP
#define FLOOR_TEST_HPP 

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

TEST(FloorTest, simple) {
     Base* A = new Floor(new Add(15, 15.6));//30
     Base* S = new Floor(new Sub(15.6, 15));//0
     Base* M = new Floor(new Mult(1.3, 2));//2
     Base* D = new Floor(new Div(8, 5));//1
     Base* P = new Floor(new Pow(4, 0.5));//2
     Base* temp = new Add(A, S);//30
     Base* temp2 = new Add(D, P);//3
     Base* temp3 = new Add(temp, temp2);//33
     Base* test = new Floor(new Div(temp3, M));//16
     EXPECT_EQ(A->evaluate(), 30);
     EXPECT_EQ(S->evaluate(), 0);
     EXPECT_EQ(M->evaluate(), 2);
     EXPECT_EQ(D->evaluate(), 1);
     EXPECT_EQ(P->evaluate(), 2);
     EXPECT_EQ(temp->evaluate(), 30);
     EXPECT_EQ(temp2->evaluate(), 3);
     EXPECT_EQ(temp3->evaluate(), 33);
     EXPECT_EQ(test->evaluate(), 16);
     EXPECT_EQ(test->stringify(), "((((15.000000 + 15.600000) + (15.600000 - 15.000000)) + ((8.000000 / 5.000000) + (4.000000**0.500000))) / (1.300000 * 2.000000))"); 
}

TEST(FloorTest, simpleZero) {
     Base* test = new Floor(new Op(0));
     EXPECT_EQ(test->evaluate(), 0);
     EXPECT_EQ(test->stringify(), "0.000000");
}

TEST(FloorTest, classes) {
     Base* CeilAdd = new Ceil(new Add(2.5,1));
     Base* ParenTruncPow = new Paren(new Trunc(new Pow(CeilAdd,2)));
     Base* AbsSub = new Abs(new Sub(ParenTruncPow,800));
     Base* FloorAbsDiv = new Floor(new Abs(new Div(4.5,-2.2)));
     Base* test = new Paren(new Mult(AbsSub, FloorAbsDiv));

     EXPECT_EQ(test->evaluate(), 1568);
     EXPECT_EQ(test->stringify(), "((((16.000000) - 800.000000) * (4.500000 / -2.200000)))");

}
#endif
