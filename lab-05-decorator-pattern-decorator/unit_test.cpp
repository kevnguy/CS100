#include "gtest/gtest.h"

#include "header/abs_test.hpp"
#include "header/paren_test.hpp"
#include "header/ceil_test.hpp"
#include "header/floor_test.hpp"
#include "header/trunc_test.hpp"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
