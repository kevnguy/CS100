CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

SET(CMAKE_CXX_STANDARD 11)

ADD_SUBDIRECTORY(googletest
)

ADD_EXECUTABLE(test
   unit_test.cpp src/unary_iterator.cpp src/preorder_iterator.cpp src/binary_iterator.cpp src/visitor
)

ADD_EXECUTABLE(tree
   main.cpp src/unary_iterator.cpp src/preorder_iterator.cpp src/binary_iterator.cpp src/visitor
)

TARGET_LINK_LIBRARIES(test gtest)
TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)

TARGET_LINK_LIBRARIES(tree gtest)
TARGET_COMPILE_DEFINITIONS(tree PRIVATE gtest_disable_pthreads=ON)
