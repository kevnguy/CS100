#ifndef ITERATOR_TEST_HPP
#define ITERATOR_TEST_HPP 

#include "gtest/gtest.h"
#include "iterator.hpp"

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
#include "rand.hpp"

TEST(ItTest, Abs) {
     Base* DnewS = new Ceil(new Abs(new Sub(10,190)));
    	Iterator* test = DnewS->create_iterator();
     EXPECT_EQ(test->current()->evaluate(), 180);
	test->next();
	EXPECT_TRUE(test->is_done());
}

TEST(ItTest, Ceil) {
	Base* A = new Add(9.4, 2.3);
     Base* DnewS = new Ceil(new Ceil(A));
        Iterator* test = DnewS->create_iterator();
     EXPECT_EQ(test->current()->evaluate(), 12);
        test->next();
        EXPECT_TRUE(test->is_done());
}

TEST(ItTest, Floor) {
	Base* S = new Sub(10.4,190);
     Base* DnewS = new Floor(new Floor(S));
        Iterator* test = DnewS->create_iterator();
     EXPECT_EQ(test->current()->evaluate(), -180);
        test->next();
        EXPECT_TRUE(test->is_done());
}

TEST(ItTest, Paren) {
        Base* S = new Sub(10.4,190.1);
     Base* DnewS = new Ceil(new Paren(S));
        Iterator* test = DnewS->create_iterator();
     EXPECT_EQ(test->current()->stringify(), "((10.400000 - 190.100000))");
        test->next();
        EXPECT_TRUE(test->is_done());
}

TEST(ItTest, Trunc) {
        Base* S = new Sub(10.4,190.1);
     Base* DnewS = new Ceil(new Trunc(S));
        Iterator* test = DnewS->create_iterator();
     EXPECT_EQ(test->current()->stringify(), "-179.700000");
        test->next();
        EXPECT_TRUE(test->is_done());
}

TEST(ItTest, Add){
	Add* A = new Add(6,4);
	Iterator* test = A->create_iterator();
	EXPECT_EQ(test->current()->stringify(),"6.000000");
	test->next();
	EXPECT_EQ(test->current()->stringify(),"4.000000");
	test->next();
	EXPECT_TRUE(test->is_done());
}
TEST(ItTest, Sub){
        Sub* S = new Sub(6,4);
        Iterator* test = S->create_iterator();
        EXPECT_EQ(test->current()->stringify(),"6.000000");
        test->next();
        EXPECT_EQ(test->current()->stringify(),"4.000000");
        test->next();
        EXPECT_TRUE(test->is_done());
}
TEST(ItTest, Mult){
        Mult* M = new Mult(6,4);
        Iterator* test = M->create_iterator();
        EXPECT_EQ(test->current()->stringify(),"6.000000");
        test->next();
        EXPECT_EQ(test->current()->stringify(),"4.000000");
        test->next();
        EXPECT_TRUE(test->is_done());
}
TEST(ItTest, Div){
        Div* D = new Div(6,4);
        Iterator* test = D->create_iterator();
        EXPECT_EQ(test->current()->stringify(),"6.000000");
        test->next();
        EXPECT_EQ(test->current()->stringify(),"4.000000");
        test->next();
        EXPECT_TRUE(test->is_done());
}
TEST(ItTest, Pow){
        Pow* P = new Pow(2,3);
        Iterator* test = P->create_iterator();
        EXPECT_EQ(test->current()->stringify(),"2.000000");
        test->next();
        EXPECT_EQ(test->current()->stringify(),"3.000000");
        test->next();
        EXPECT_TRUE(test->is_done());
}
TEST(ItTest, Rand){
        Rand* R = new Rand();
        Iterator* test = R->create_iterator();
	EXPECT_EQ(test->current(), nullptr);
        EXPECT_TRUE(test->is_done());
}
TEST(ItTest, Op){
        Op* O = new Op(6);
        Iterator* test = O->create_iterator();
	EXPECT_EQ(test->current(), nullptr);
	EXPECT_TRUE(test->is_done());
}


#endif
