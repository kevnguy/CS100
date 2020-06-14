#ifndef RAND_TEST_HPP
#define RAND_TEST_HPP

#include "gtest/gtest.h"

#include "rand.hpp"

TEST(RandTest, RandTest1) {
    Rand* test = new Rand();
    EXPECT_LT(test->evaluate(), 100);
    EXPECT_EQ(std::to_string(test->evaluate()), test->stringify());
}

TEST(RandTest, RandTest2) {
    Rand* test = new Rand();
    EXPECT_LT(test->evaluate(), 100);
    EXPECT_EQ(std::to_string(test->evaluate()), test->stringify());
}

TEST(RandTest, RandTest3) {
    Rand* test = new Rand();
    EXPECT_LT(test->evaluate(), 100);
    EXPECT_EQ(std::to_string(test->evaluate()), test->stringify());
}

#endif
