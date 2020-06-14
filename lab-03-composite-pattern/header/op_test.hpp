#ifndef OP_TEST_HPP
#define OP_TEST_HPP

#include "gtest/gtest.h"

#include "op.hpp"

TEST(OpTest, OpZero) {
    Op* test = new Op(0);
    EXPECT_EQ(test->evaluate(), 0);
    EXPECT_EQ(test->stringify(), "0.000000");
}

TEST(OpTest, OpNonZero) {
    Op* test = new Op(999999.5);
    EXPECT_EQ(test->evaluate(), 999999.5);
    EXPECT_EQ(test->stringify(), "999999.500000");
}

TEST(OpTest, OpNegNonZero) {
    Op* test = new Op(-111111.1);
    EXPECT_EQ(test->evaluate(), -111111.1);
    EXPECT_EQ(test->stringify(), "-111111.100000");
}
#endif //__OP_TEST_HPP__
