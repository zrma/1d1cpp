//
// Created by zrma on 2019-09-08.
//

#include "gtest/gtest.h"

#include "../../src/hacker_rank/stl.h"

// https://www.hackerrank.com/challenges/vector-sort/problem
TEST(sort, test_eq) {
  auto actual = std::vector<int>{1, 6, 10, 8, 4};
  auto expected = std::vector<int>{1, 4, 6, 8, 10};
  sort(actual);
  EXPECT_EQ(actual, expected);
}