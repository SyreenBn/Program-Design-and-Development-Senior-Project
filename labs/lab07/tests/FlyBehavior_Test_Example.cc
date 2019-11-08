// Google Test Framework
#include <gtest/gtest.h>
// Project code from the ../src directory
#include "../src/FlyBehavior.h"
#include <string.h>

#ifdef FEEDBACK_TEST_02

TEST(FlyBehaviorTest, fly) {
  FlyBehavior my_flybehavior;
  string expect_str="Generic Flying at 5 mph.";
  EXPECT_STREQ(expect_str.c_str(),my_flybehavior.fly().c_str())<< "FAIL: fly function!";
}

TEST(FlyWithWings, fly) {
  FlyWithWings my_flybehavior;
  string expect_str="Fly with wings at speed of 5 mph.";
  EXPECT_STREQ(expect_str.c_str(),my_flybehavior.fly().c_str())<< "FAIL: fly function!";
}

TEST(NoFly, fly) {
  NoFly my_flybehavior;
  string expect_str="Cannot fly.";
  EXPECT_STREQ(expect_str.c_str(),my_flybehavior.fly().c_str())<< "FAIL: fly function!";
}

TEST(FlyWithRocket, Constructor) {
  FlyWithRocket my_flybehavior;
  string expect_str="Fly with wings at speed of 20 mph.";
  EXPECT_STREQ(expect_str.c_str(),my_flybehavior.fly().c_str())<< "FAIL: fly function!";
}

TEST(FlyWithRocket, fly) {
  FlyWithRocket my_flybehavior1;
  string expect_str1="Fly with wings at speed of 20 mph.";
  EXPECT_STREQ(expect_str1.c_str(),my_flybehavior1.fly().c_str())<< "FAIL: fly function!";
}
#endif
