#ifndef LIST_CONTAINER_TEST
#define LIST_CONTAINER_TEST

#include "gtest/gtest.h"

#include "../header/op.hpp"
#include "../header/mult.hpp"
#include "../header/div.hpp"
#include "../header/add.hpp"
#include "../header/sub.hpp"
#include "../header/pow.hpp"
#include "../header/listContainer.hpp"
#include "../header/bubbleSort.hpp"

TEST(ListContainerTest, addElements) {
    Base* newA = new Add(1.0,2.0);
    Base* newS = new Sub(5.0,4.0);
    Base* newM = new Mult(-1.0,3.0);

    ListContainer* container = new ListContainer();

    container->add_element(newA);
    container->add_element(newS);
    container->add_element(newM);

    ASSERT_EQ(container->size(), 3);
    EXPECT_DOUBLE_EQ(container->at(0)->evaluate(), 3.0);
    EXPECT_DOUBLE_EQ(container->at(1)->evaluate(), 1.0);
    EXPECT_DOUBLE_EQ(container->at(2)->evaluate(), -3.0);

}

TEST(ListContainerTest, printElements) {
    Base* newA = new Add(1.0,2.0);
    Base* newS = new Sub(5.0,4.0);
    Base* newM = new Mult(-1.0,3.0);
    Base* newP = new Pow(newA, newS);
    Base* newD = new Div(newA, newM);

    ListContainer* container = new ListContainer();

    container->add_element(newA);
    container->add_element(newS);
    container->add_element(newM);
    container->add_element(newP);
    container->add_element(newD);

    ASSERT_EQ(container->size(), 5);
    EXPECT_DOUBLE_EQ(container->at(0)->evaluate(), 3.0);
    EXPECT_DOUBLE_EQ(container->at(1)->evaluate(), 1.0);
    EXPECT_DOUBLE_EQ(container->at(2)->evaluate(), -3.0);
    EXPECT_DOUBLE_EQ(container->at(3)->evaluate(), 3.0);
    EXPECT_DOUBLE_EQ(container->at(4)->evaluate(), -1.0);
    testing::internal::CaptureStdout();
    container->print();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "(1.000000 + 2.000000)\n(5.000000 - 4.000000)\n(-1.000000 * 3.000000)\n((1.000000 + 2.000000)**(5.000000 - 4.000000))\n((1.000000 + 2.000000) / (-1.000000 * 3.000000))\n");

}

TEST(ListContainerTest, SwapTestSimple) {
    Base* seven = new Op(7);
    Base* eight = new Op(8);
    Base* nine = new Op(9);
    ListContainer* test_container = new ListContainer();

    test_container->add_element(seven);
    test_container->add_element(eight);
    test_container->add_element(nine);
    test_container->swap(0,2);
    test_container->swap(1,2);

    ASSERT_EQ(test_container->size(), 3);
    EXPECT_EQ(test_container->at(0)->evaluate(), 9);
    EXPECT_EQ(test_container->at(1)->evaluate(), 7);
    EXPECT_EQ(test_container->at(2)->evaluate(), 8);
}

TEST(ListContainerTest, SwapTestMultple) {
    Base* seven = new Op(7);
    Base* eight = new Op(8);
    Base* nine = new Op(9);
    Base* four = new Op(4); 
    Base* three = new Op(3); 
    Base* two = new Op(2);
   ListContainer* test_container = new ListContainer();

    test_container->add_element(seven);
    test_container->add_element(eight);
    test_container->add_element(nine);
    test_container->add_element(four);
    test_container->add_element(three);
    test_container->add_element(two);
    test_container->swap(0,1);
    test_container->swap(2,3);
    test_container->swap(4,5);
    test_container->swap(0,5);
    test_container->swap(1,4);
    test_container->swap(2,3);

    ASSERT_EQ(test_container->size(), 6);
    EXPECT_EQ(test_container->at(0)->evaluate(), 3);
    EXPECT_EQ(test_container->at(1)->evaluate(), 2);
    EXPECT_EQ(test_container->at(2)->evaluate(), 9);
    EXPECT_EQ(test_container->at(3)->evaluate(), 4);
    EXPECT_EQ(test_container->at(4)->evaluate(), 7);
    EXPECT_EQ(test_container->at(5)->evaluate(), 8);
}

#endif
