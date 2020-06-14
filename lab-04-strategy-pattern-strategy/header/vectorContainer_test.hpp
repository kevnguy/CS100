#ifndef VECTOR_CONTAINER_TEST
#define VECTOR_CONTAINER_TEST

#include "gtest/gtest.h"

#include "../header/op.hpp"
#include "../header/mult.hpp"
#include "../header/div.hpp"
#include "../header/add.hpp"
#include "../header/sub.hpp"
#include "../header/pow.hpp"
#include "../header/vectorContainer.hpp"
#include "../header/selectionSort.hpp"

TEST(VectorContainerTest, addElements) {
    Base* newA = new Add(1.0,2.0);
    Base* newS = new Sub(5.0,4.0);
    Base* newM = new Mult(-1.0,3.0);

    VectorContainer* container = new VectorContainer();

    container->add_element(newA);
    container->add_element(newS);
    container->add_element(newM);

    ASSERT_EQ(container->size(), 3);
    EXPECT_DOUBLE_EQ(container->at(0)->evaluate(), 3.0);
    EXPECT_DOUBLE_EQ(container->at(1)->evaluate(), 1.0);
    EXPECT_DOUBLE_EQ(container->at(2)->evaluate(), -3.0);

}

TEST(VectorContainerTest, printElements) {
    Base* newA = new Add(1.0,2.0);
    Base* newS = new Sub(5.0,4.0);
    Base* newM = new Mult(-1.0,3.0);
    Base* newP = new Pow(newA, newS);
    Base* newD = new Div(newA, newM);

    VectorContainer* container = new VectorContainer();

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

TEST(VectorContainerTest, SwapTest) {
    Base* seven = new Op(7);
    Base* eight = new Op(8);
    Base* nine = new Op(9);
    VectorContainer* test_container = new VectorContainer();

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

TEST(VectorContainerTest, SwapTestSingle) {
    Base* seven = new Op(7);
    VectorContainer* test_container = new VectorContainer();

    test_container->add_element(seven);
    test_container->swap(0,0);

    ASSERT_EQ(test_container->size(), 1);
    EXPECT_EQ(test_container->at(0)->evaluate(), 7);
}
#endif
