//
// Created by zrma on 2019-09-06.
//

#include "gtest/gtest.h"

#include "../../src/hacker_rank/structs.h"

// https://www.hackerrank.com/challenges/c-tutorial-struct/problem
TEST(create_structs, test_eq) {
  const auto age = 15;
  const auto first_name = "john";
  const auto last_name = "carmack";
  const auto standard = 10;
  const auto s1 = create_structs(age, first_name, last_name, standard);
  const auto s2 = std::make_shared<Student>(age, first_name, last_name, standard);
  EXPECT_EQ(s1->age, s2->age);
  EXPECT_EQ(s1->first_name, s2->first_name);
  EXPECT_EQ(s1->last_name, s2->last_name);
  EXPECT_EQ(s1->standard, s2->standard);
}