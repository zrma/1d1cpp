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

// https://www.hackerrank.com/challenges/vector-erase/problem
TEST(erase, test_eq) {
    {
        auto actual = std::vector<int>{1, 4, 6, 2, 8, 9};
        auto expected = std::vector<int>{1, 8, 9};
        erase(actual, 2, 2, 4);
        EXPECT_EQ(actual, expected);
    }
    {
        auto actual = std::vector<int>{
                954614030, 287810799, 817527589, 723345936, 829663028, 455978854, 38514099, 857999595, 398919413,
                101866261,
                600097141, 840446071, 81428809, 56981383, 535315635, 351838330, 654452695, 696103243, 265015686,
                342013403,
                375258424, 908740659, 978964505, 491819237, 682450746, 720698256, 716968168, 560268161, 256444186,
                726361207,
                276503811, 513824639, 536303048, 918150142, 388254284, 887819469, 413429798, 356863358, 241921972,
                380179901,
                305143113, 375800530, 31322497, 163379011, 435104438, 909341335, 309385611, 763900725, 761690277,
                406352490,
                237517178, 774299273, 799940161, 84919084, 248572681, 730664345, 254885862, 134991681, 809281094,
                710637154,
                894647137, 506262731, 54842831, 465730751, 507961907, 636104179, 56293141, 742924466, 795190734,
                904744225,
                293251228, 516146844, 530950101, 928324414, 589820473, 867684224, 879531616, 610481657, 944939858,
                108266307,
                180166197, 612981758, 432907041, 320440558, 445810448, 343370048, 328306417, 240562410, 944646107,
                74262831,
                21363807, 292796738, 714548470, 597639426, 310751641, 25086948, 829279856, 959813615, 816227234,
                980883168
        };
        auto expected = std::vector<int>{
                954614030, 287810799, 817527589, 723345936, 829663028, 455978854, 38514099, 857999595, 398919413,
                101866261,
                600097141, 840446071, 81428809, 56981383, 535315635, 351838330, 654452695, 696103243, 342013403,
                375258424,
                908740659, 978964505, 491819237, 682450746, 720698256, 716968168, 560268161, 256444186, 726361207,
                276503811,
                513824639, 536303048, 918150142, 388254284, 710637154, 894647137, 506262731, 54842831, 465730751,
                507961907,
                636104179, 56293141, 742924466, 795190734, 904744225, 293251228, 516146844, 530950101, 928324414,
                589820473,
                867684224, 879531616, 610481657, 944939858, 108266307, 180166197, 612981758, 432907041, 320440558,
                445810448,
                343370048, 328306417, 240562410, 944646107, 74262831, 21363807, 292796738, 714548470, 597639426,
                310751641,
                25086948, 829279856, 959813615, 816227234, 980883168
        };
        erase(actual, 19, 35, 59);
        EXPECT_EQ(actual, expected);
    }
}

// https://www.hackerrank.com/challenges/cpp-lower-bound/problem
TEST(lower_bound_stl, test_eq) {
    const auto v = std::vector<int>{1, 1, 2, 2, 6, 9, 9, 15};
    {
        testing::internal::CaptureStdout();
        lower_bound_stl(v, 1);
        auto output = testing::internal::GetCapturedStdout();
        EXPECT_EQ(output, "Yes 1\n");
    }
    {
        testing::internal::CaptureStdout();
        lower_bound_stl(v, 4);
        auto output = testing::internal::GetCapturedStdout();
        EXPECT_EQ(output, "No 5\n");
    }
    {
        testing::internal::CaptureStdout();
        lower_bound_stl(v, 9);
        auto output = testing::internal::GetCapturedStdout();
        EXPECT_EQ(output, "Yes 6\n");
    }
    {
        testing::internal::CaptureStdout();
        lower_bound_stl(v, 15);
        auto output = testing::internal::GetCapturedStdout();
        EXPECT_EQ(output, "Yes 8\n");
    }
}

// https://www.hackerrank.com/challenges/cpp-lower-bound/problem
TEST(sets_stl, test_eq) {
    const auto v = std::vector<std::tuple<int, int>>{
            std::make_tuple<int, int>(1, 9),
            std::make_tuple<int, int>(1, 6),
            std::make_tuple<int, int>(1, 10),
            std::make_tuple<int, int>(1, 4),
            std::make_tuple<int, int>(3, 6),
            std::make_tuple<int, int>(3, 14),
            std::make_tuple<int, int>(2, 6),
            std::make_tuple<int, int>(3, 6),
    };
    testing::internal::CaptureStdout();
    sets_stl(v);
    auto output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Yes\nNo\nNo\n");
}