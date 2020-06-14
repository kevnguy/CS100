#include "c-echo.h"
#include "c-count.h"

#include "gtest/gtest.h"

TEST(EchoTest, HelloWorld) {
    char* test_val[3]; test_val[0] = "./c-echo.count"; test_val[1] = "hello"; test_val[2] = "world";
    EXPECT_EQ("hello world", echo(3,test_val));
}

TEST(EchoTest, EmptyString) {
    char* test_val[1]; test_val[0] = "./c-echo.count";
    EXPECT_EQ("", echo(1,test_val));
}

TEST(EchoTest, Alphabet) {
    char* test_val[3]; test_val[0] = "./c-echo.count"; test_val[1] = "abcdefghijklm"; test_val[2] = "nopqrstuvwxyz";
    EXPECT_EQ("abcdefghijklm nopqrstuvwxyz", echo(3,test_val));
}

TEST(EchoTest, SimpleSpecialChar) {
    char* test_val[2]; test_val[0] = "./c-echo.count"; test_val[1] = "!@#$%^&*()_+"; 
    EXPECT_EQ("!@#$%^&*()_+", echo(2,test_val));
}

TEST(EchoTest, AlphaNumSpecial) {
    char* test_val[4]; test_val[0] = "./c-echo.count"; test_val[1] = "AAaaBBbbCCccXXxxYYyyZZzz";
    test_val[2] = "1234567890"; test_val[3] = "+_)(*&^%$#@!";
    EXPECT_EQ("AAaaBBbbCCccXXxxYYyyZZzz 1234567890 +_)(*&^%$#@!", echo(4,test_val));
}

TEST(CountTest, HelloWorld) {
    std::string test_str = "hello world";
    EXPECT_EQ(2, count(test_str));
}

TEST(CountTest, EmptyString) {
    std::string test_str = "";
    EXPECT_EQ(0, count(test_str));
}

TEST(CountTest, ManySpaces) {
    std::string test_str = "   this   string has     weird   spacing";
    EXPECT_EQ(5, count(test_str));
}



int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
