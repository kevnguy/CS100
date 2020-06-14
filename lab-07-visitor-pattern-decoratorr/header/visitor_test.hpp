#ifndef VISITOR_TEST_HPP
#define VISITOR_TEST_HPP 

#include "gtest/gtest.h"
#include "iterator.hpp"
#include "visitor.hpp"

#include "op.hpp"
#include "rand.hpp"
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

TEST(VisitorTest, singles) {
	Base* o1 = new Op(1);
	Base* o2 = new Op(1);
	Base* r1 = new Rand();
	Base* r2 = new Rand();
	Base* a1 = new Add(1,1);
	Base* s1 = new Sub(1,1);
	Base* m1 = new Mult(1,11);
	Base* d1 = new Div(1,1);
	Base* p1 = new Pow(1,1);
	
	CountVisitor* v = new CountVisitor();
	o1->accept(v);
	o2->accept(v);
	r1->accept(v);
	r2->accept(v);
	a1->accept(v);
	s1->accept(v);
	m1->accept(v);
	d1->accept(v);
	p1->accept(v);

	EXPECT_EQ(v->op_count(), 2);
	EXPECT_EQ(v->rand_count(), 2);
	EXPECT_EQ(v->add_count(), 1);
	EXPECT_EQ(v->mult_count(), 1);
	EXPECT_EQ(v->sub_count(), 1);
	EXPECT_EQ(v->div_count(), 1);
	EXPECT_EQ(v->pow_count(), 1);
}

TEST(VisitorTest, xpTree) {
     Base* PnewA = new Paren(new Add(new Rand(),1.0));
     Base* FCnewP = new Floor(new Ceil(new Pow(PnewA,2)));
     Base* DnewS = new Abs(new Sub(FCnewP,190));
     Base* DnewD = new Abs(new Div(4,-2));
     Base* test = new Paren(new Trunc(new Mult(DnewS, DnewD)));

     Iterator* it = new PreorderIterator(test);
     CountVisitor* v = new CountVisitor();
     it->first();
     while(!it->is_done()){
        Base* temp = it->current();
        temp->accept(v);
        it->next();
     }

     EXPECT_EQ(v->op_count(), 5);
     EXPECT_EQ(v->rand_count(), 1);
     EXPECT_EQ(v->add_count(), 1);
     EXPECT_EQ(v->mult_count(), 1);
     EXPECT_EQ(v->sub_count(), 1);
     EXPECT_EQ(v->div_count(), 1);
     EXPECT_EQ(v->pow_count(), 1);
     EXPECT_EQ(v->ceil_count(), 1);
     EXPECT_EQ(v->trunc_count(), 1);
     EXPECT_EQ(v->paren_count(), 1);
     EXPECT_EQ(v->floor_count(), 1);
     EXPECT_EQ(v->abs_count(), 2);
}

TEST(VisitorTest, xpTree2) {
     Base* CnewA = new Ceil(new Add(9.5,1.2));
     Base* PTnewP = new Paren(new Trunc(new Pow(CnewA,2)));
     Base* AnewS = new Abs(new Sub(PTnewP,190));
     Base* FAnewD = new Floor(new Abs(new Div(4.5,-2.2)));
     Base* test = new Paren(new Mult(AnewS, FAnewD));

     Iterator* it = new PreorderIterator(test);
     CountVisitor* v = new CountVisitor();
     it->first();
     while(!it->is_done()){
	Base* temp = it->current();
	temp->accept(v);
	it->next();
     }
     EXPECT_EQ(test->evaluate(), 138);
     EXPECT_EQ(test->stringify(), "((((121.000000) - 190.000000) * (4.500000 / -2.200000)))");
     EXPECT_EQ(v->op_count(), 6);
     EXPECT_EQ(v->rand_count(), 0);
     EXPECT_EQ(v->add_count(), 1);
     EXPECT_EQ(v->mult_count(), 1);
     EXPECT_EQ(v->sub_count(), 1);
     EXPECT_EQ(v->div_count(), 1);
     EXPECT_EQ(v->pow_count(), 1);
     EXPECT_EQ(v->ceil_count(), 1);
     EXPECT_EQ(v->trunc_count(), 1);
     EXPECT_EQ(v->paren_count(), 1);
     EXPECT_EQ(v->floor_count(), 1);
     EXPECT_EQ(v->abs_count(), 2);
}
#endif

