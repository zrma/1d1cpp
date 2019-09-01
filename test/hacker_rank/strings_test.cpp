//
// Created by zrma on 2019-08-31.
//

#include "gtest/gtest.h"

#include "../../src/hacker_rank/strings.h"

// https://www.hackerrank.com/challenges/c-tutorial-stringstream/problem
TEST(parse_int, test_eq) {
    {
        const auto actual = parse_int("23,4,56");
        const auto expected = std::vector{23, 4, 56};
        EXPECT_EQ(actual, expected);
    }
    {
        const auto actual = parse_int("23,4,56,");
        const auto expected = std::vector{23, 4, 56};
        EXPECT_EQ(actual, expected);
    }
}

// https://www.hackerrank.com/challenges/c-tutorial-strings/problem
TEST(strings, test_eq) {
    testing::internal::CaptureStdout();
    strings("abcd", "ef");
    auto output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "4 2\nabcdef\nebcd af\n");
}