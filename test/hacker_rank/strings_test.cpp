//
// Created by zrma on 2019-08-31.
//

#include "gtest/gtest.h"

#include "../../src/hacker_rank/strings.h"

// https://www.hackerrank.com/challenges/c-tutorial-stringstream/problem
TEST(parse_int, test_eq) {
    {
        const auto actual = parse_int("23,4,56");
        const auto expected = std::vector<int>{23, 4, 56};
        EXPECT_EQ(actual, expected);
    }
    {
        const auto actual = parse_int("23,4,56,");
        const auto expected = std::vector<int>{23, 4, 56};
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

// https://www.hackerrank.com/challenges/attribute-parser/problem
TEST(attribute_parser, test_eq) {
    testing::internal::CaptureStdout();
    attribute_parser({
                             "<tag1 value = \"HelloWorld\">",
                             "<tag2 name = \"Name1\">",
                             "</tag2>",
                             "</tag1>"
                     }, {
                             "tag1.tag2~name",
                             "tag1~name",
                             "tag1~value"
                     });
    auto output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Name1\nNot Found!\nHelloWorld\n");
}

TEST(parse_attr, test_eq) {
    EXPECT_EQ(parse_attr("<tag1 name = \"Name1\" value = \"HelloWorld\">"),
              std::make_tuple(
                      "tag1",
                      pair_map{
                              std::make_pair("name", "Name1"),
                              std::make_pair("value", "HelloWorld"),
                      }
              ));
}

TEST(parse_query, test_eq) {
    EXPECT_EQ(parse_query("tag1.tag2~name"),
              std::make_tuple(
                      "name",
                      std::list<std::string>{"tag1", "tag2"}
              ));
}
