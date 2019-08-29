//
// Created by zrma on 2019-08-28.
//

#include "gtest/gtest.h"

#include "../../src/hacker_rank/introduction.h"

// https://www.hackerrank.com/challenges/cpp-hello-world/problem
TEST(hello_world, test_eq) {
    testing::internal::CaptureStdout();
    hello_world();
    auto output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Hello, World!");
}

// https://www.hackerrank.com/challenges/cpp-input-and-output/problem
TEST(input_and_output, test_eq) {
    testing::internal::CaptureStdout();
    input_and_output({1, 2, 7});
    auto output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "10");
}

// https://www.hackerrank.com/challenges/c-tutorial-conditional-if-else/problem
TEST(conditional_statements, test_eq) {
    testing::internal::CaptureStdout();
    conditional_statements(5);
    auto output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "five");

    conditional_statements(8);
    output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "eight");

    conditional_statements(44);
    output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Greater than 9");
}