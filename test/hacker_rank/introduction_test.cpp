//
// Created by zrma on 2019-08-28.
//

#include "gtest/gtest.h"

#include "../../src/hacker_rank/introduction.h"

// https://www.hackerrank.com/challenges/cpp-hello-world/problem
TEST(hello_world, test_eq) {
    testing::internal::CaptureStdout();
    hello_world();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Hello, World!");
}

// https://www.hackerrank.com/challenges/cpp-input-and-output/problem
TEST(input_and_output, test_eq) {
    testing::internal::CaptureStdout();
    input_and_output({1, 2, 7});
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "10");
}