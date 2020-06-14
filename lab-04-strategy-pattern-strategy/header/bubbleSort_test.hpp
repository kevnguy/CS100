#ifndef BUBBLE_SORT_TEST
#define BUBBLE_SORT_TEST

#include "gtest/gtest.h"
#include "../header/mult.hpp"
#include "../header/div.hpp"
#include "../header/sub.hpp"
#include "../header/pow.hpp"
#include "../header/add.hpp"
#include "../header/selectionSort.hpp"
#include "../header/vectorContainer.hpp"

TEST(BubbleSortTestSet, BubbleSortTestList) {
    Op* seven = new Op(7);
    Op* four = new Op(4);
    Mult* TreeA = new Mult(seven, four);

    Op* three = new Op(3);
    Op* two = new Op(2);
    Add* TreeB = new Add(three, two);

    Op* ten = new Op(10);
    Op* six = new Op(6);
    Sub* TreeC = new Sub(ten, six);

    Base* newP = new Pow(13,2);
    
    Base* newD = new Div(1,1);

   
    ListContainer* container = new ListContainer();
    container->add_element(TreeA);
    container->add_element(TreeB);
    container->add_element(TreeC);
    container->add_element(newP);
    container->add_element(newD);

    ASSERT_EQ(container->size(), 5);
    EXPECT_EQ(container->at(0)->evaluate(), 28);
    EXPECT_EQ(container->at(1)->evaluate(), 5);
    EXPECT_EQ(container->at(2)->evaluate(), 4);
    EXPECT_EQ(container->at(3)->evaluate(), 169);
    EXPECT_EQ(container->at(4)->evaluate(), 1);

    container->set_sort_function(new SelectionSort());
    container->sort();

    ASSERT_EQ(container->size(), 5);
    EXPECT_EQ(container->at(0)->evaluate(), 1);
    EXPECT_EQ(container->at(1)->evaluate(), 4);
    EXPECT_EQ(container->at(2)->evaluate(), 5);
    EXPECT_EQ(container->at(3)->evaluate(), 28);
    EXPECT_EQ(container->at(4)->evaluate(), 169);

}

TEST(BubbleSortTestSet, BubbleSortTestVector) {
	Op* five = new Op(5);
	Op* six = new Op(6);
	Add* TreeA = new Add(five, six);//11

	Op* eight = new Op(8);
	Op* four = new Op(4);
	Div* TreeB = new Div(eight, four);//2

	Op* one = new Op(1);
	Op* seven = new Op(7);
	Mult* TreeC = new Mult(one, seven);//7

	Op* two = new Op(2);
	Op* three = new Op(3);
	Pow* TreeD = new Pow(two, three);//8

	Base* newM = new Mult(10,3);//30
	Base* newD = new Div(newM, 5);//6

	VectorContainer* container = new VectorContainer();
	container->add_element(TreeA);
	container->add_element(TreeB);
	container->add_element(TreeC);
	container->add_element(TreeD);
	container->add_element(newD);
	container->add_element(newM);

	ASSERT_EQ(container->size(), 6);
	EXPECT_EQ(container->at(0)->evaluate(), 11);
        EXPECT_EQ(container->at(1)->evaluate(), 2);
        EXPECT_EQ(container->at(2)->evaluate(), 7);
        EXPECT_EQ(container->at(3)->evaluate(), 8);
        EXPECT_EQ(container->at(4)->evaluate(), 6);
        EXPECT_EQ(container->at(5)->evaluate(), 30);

        container->set_sort_function(new BubbleSort());
        container->sort();

	ASSERT_EQ(container->size(), 6);
	EXPECT_EQ(container->at(0)->evaluate(), 2);
        EXPECT_EQ(container->at(1)->evaluate(), 6);
        EXPECT_EQ(container->at(2)->evaluate(), 7);
        EXPECT_EQ(container->at(3)->evaluate(), 8);
        EXPECT_EQ(container->at(4)->evaluate(), 11);
        EXPECT_EQ(container->at(5)->evaluate(), 30);
}

TEST(BubbleSortTestSet, BubbleSortTestBoth){
    Op* zero = new Op(0);
    Op* one = new Op(1);
    VectorContainer* container1 = new VectorContainer();
    ListContainer* container2 = new ListContainer();

    container1->add_element(zero);	
    container2->add_element(zero);
    container1->add_element(one);
    container2->add_element(one);	

    container1->set_sort_function(new BubbleSort());
    container2->set_sort_function(new BubbleSort());
    
    ASSERT_EQ(container1->size(), 2);
    EXPECT_EQ(container1->at(0)->evaluate(), 0);
    EXPECT_EQ(container1->at(1)->evaluate(),1);

    ASSERT_EQ(container2->size(), 2);
    EXPECT_EQ(container2->at(0)->evaluate(), 0);
    EXPECT_EQ(container2->at(1)->evaluate(),1);

    container1->sort();
    container2->sort();

    ASSERT_EQ(container1->size(), 2);
    EXPECT_EQ(container1->at(0)->evaluate(), 0);
    EXPECT_EQ(container1->at(1)->evaluate(),1);

    ASSERT_EQ(container2->size(), 2);
    EXPECT_EQ(container2->at(0)->evaluate(), 0);
    EXPECT_EQ(container1->at(1)->evaluate(),1);

	
}

#endif
