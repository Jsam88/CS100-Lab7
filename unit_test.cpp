#include "gtest/gtest.h"
#include "../header/Factory.hpp"

TEST(FactoryTest, OpTest){
    const char* input[] = {"./test", "8"};
    int numInputs = 2;
    Factory calculate;
    Base* base = calculate.parse((char**)input, numInputs);
    EXPECT_EQ(base->evaluate(), 8);
    EXPECT_EQ(base->stringify(), "8");
}

TEST(FactoryTest, AddTest){
  const char* input[] = {"./test", "8", "+", "8" };
  int userInputs = 4;
  Factory calculate;
  Base* base = calculate.parse((char**) input, userInputs);
  EXPECT_EQ(base->stringify(), "8 + 8");
  EXPECT_EQ(base->evaluate(), 16);
}

TEST(FactoryTest, SubTest){
    const char* input[] = {"./test", "5", "-", "4"};
    int numInputs = 4;
    Factory calculate;
    Base* base = calculate.parse((char**)input, numInputs);
    EXPECT_EQ(base->stringify(), "5 - 4");
    EXPECT_EQ(base->evaluate(), -1);
}

TEST(FactoryTest, MultTest){
    const char* input[] = {"./test", "5", "*", "2"};
    int numInputs = 4;
    Factory calculate;
    Base* base = calculate.parse((char**)input, numInputs);
    EXPECT_EQ(base->stringify(), "5 * 2");
    EXPECT_EQ(base->evaluate(), 10);
}

TEST(FactoryTest, DivTest){
    const char* input[] = {"./test", "4", "/", "2"};
    int numInputs = 4;
    Factory calculate;
    Base* base = calculate.parse((char**)input, numInputs);
    EXPECT_EQ(base->stringify(), "4 / 2");
    EXPECT_EQ(base->evaluate(), 2);
}

TEST(FactoryTest, PowTest){
    const char* input[] = {"./test", "2", "**", "2"};
    int numInputs = 4;
    Factory calculate;
    Base* base = calculate.parse((char**)input, numInputs);
    EXPECT_EQ(base->stringify(), "2 ** 2");
    EXPECT_EQ(base->evaluate(), 4);
}


TEST(FactoryTest, MultiOperators){
    const char* input[] = {"./test", "10", "+", "8", "-", "8", "/", "2", "*", "2", "**", "2"};
    int numInputs = 12;
    Factory calculate;
    Base* base = calculate.parse((char**)input, numInputs);
    EXPECT_EQ(base->evaluate(), 100);
}

TEST(FactoryTest, InvalidInput){
    const char* input[] = {"./test"};
    int numInputs = 1;
    Factory calculate;
    Base* base = calculate.parse((char**)input, numInputs);
    EXPECT_EQ(base, nullptr);
}

TEST(FactoryTest, InvalidInput2){
    const char* input[] = {"./test", "5", "*", "7", "**"};
    int numInputs = 5;
    Factory calculate;
    Base* base = calculate.parse((char**)input, numInputs);
    EXPECT_EQ(base, nullptr);
}

TEST(FactoryTest, InvalidInput3){
    const char* input[] = {"./test", "4", "*", "4", "4" "+"};
    int numInputs = 6;
    Factory calculate;
    Base* base = calculate.parse((char**)input, numInputs);
    EXPECT_EQ(base, nullptr);
}

TEST(FactoryTest, InvalidInput4){
    const char* input[] = {"./test", "4", "4"};
    int numInputs = 3;
    Factory calculate;
    Base* base = calculate.parse((char**)input, numInputs);
    EXPECT_EQ(base, nullptr);
}

TEST(FactoryTest, NegOutput){
    const char* input[] = {"./test", "1", "-", "5"};
    int numInputs = 4;
    Factory calculate;
    Base* base = calculate.parse((char**)input, numInputs);
    EXPECT_EQ(base->stringify(), "1 - 5");
    EXPECT_EQ(base->evaluate(), -4);
}

TEST(FactoryTest, DoubleOutput1){
    const char* input[] = {"./test", "2", "*", "1.2"};
    int numInputs = 4;
    Factory calculate;
    Base* base = calculate.parse((char**)input, numInputs);
    EXPECT_EQ(base->stringify(), "2 * 1.2");
    EXPECT_NEAR(base->evaluate(), 2.4, 0.001);
}

TEST(FactoryTest, DoubleOutput2){
    const char* input[] = {"./test", "5.3", "+", "1.2"};
    int numInputs = 4;
    Factory calculate;
    Base* base = calculate.parse((char**)input, numInputs);
    EXPECT_EQ(base->stringify(), "5.3 + 1.2");
    EXPECT_NEAR(base->evaluate(), 6.5, 0.001);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
