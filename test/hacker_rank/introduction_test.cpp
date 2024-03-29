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

// https://www.hackerrank.com/challenges/c-tutorial-functions/problem
TEST(max_of_four, test_eq) {
    EXPECT_EQ(max_of_four(3, 4, 6, 5), 6);
    EXPECT_EQ(max_of_four(-1, -2, -5, -3), -1);
    EXPECT_EQ(max_of_four(0, -2, -5, 3), 3);
}

// https://www.hackerrank.com/challenges/c-tutorial-pointer/problem
TEST(update, test_eq) {
    auto a = 0, b = 0;
    update(&a, &b);
    EXPECT_EQ(a, a + b);
    EXPECT_EQ(b, std::abs(a - b));
}

// https://www.hackerrank.com/challenges/arrays-introduction/problem
TEST(arrays_introduction, test_eq) {
    testing::internal::CaptureStdout();
    arrays_introduction({1, 4, 3, 2});
    auto output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "2 3 4 1 ");
}

// https://www.hackerrank.com/challenges/variable-sized-arrays/problem
TEST(variables_sized_arrays, test_eq) {
    auto actual = variables_sized_arrays(
            {std::vector<int>{1, 5, 4}, std::vector<int>{1, 2, 8, 9, 3}},
            {std::tuple<int, int>{0, 1}, {std::tuple<int, int>{1, 3}}}
    );
    auto expected = std::vector<int>{5, 9};
    EXPECT_EQ(actual, expected);
}