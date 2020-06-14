#include "gtest/gtest.h"

#include "header/vectorContainer_test.hpp"
#include "header/selectionSort_test.hpp"
#include "header/listContainer_test.hpp"
#include "header/bubbleSort_test.hpp"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
