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

    testing::internal::CaptureStdout();
    conditional_statements(8);
    output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "eight");

    testing::internal::CaptureStdout();
    conditional_statements(44);
    output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Greater than 9");
}

// https://www.hackerrank.com/challenges/c-tutorial-basic-data-types/problem
TEST(basic_data_types, test_eq) {
    testing::internal::CaptureStdout();
    basic_data_types(3, 12345678912345, 'a', 334.23, 14049.30493);
    auto output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "3\n12345678912345\na\n334.230\n14049.304930000");
}

// https://www.hackerrank.com/challenges/c-tutorial-for-loop/problem
TEST(for_loop, test_eq) {
    testing::internal::CaptureStdout();
    for_loop(8, 11);
    auto output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "eight\nnine\neven\nodd\n");

    testing::internal::CaptureStdout();
    for_loop(3, 15);
    output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "three\nfour\nfive\nsix\nseven\neight\nnine\neven\nodd\neven\nodd\neven\nodd\n");
}