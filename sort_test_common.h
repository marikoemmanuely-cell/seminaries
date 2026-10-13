#pragma once
#include <gtest/gtest.h>
#include <vector>
#include <algorithm>
#include <random>

// Variant 14
static const std::vector<int> VARIANT{ 0, 3, 17, 8, 2, 12, 6, 19 };
static const std::vector<int> SORTED{ 0, 2, 3, 6, 8, 12, 17, 19 };

#define SORT_TEST_SUITE(Suite, sortFn)                                        \
TEST(Suite, SortsVariant14) {                                                 \
    std::vector<int> v = VARIANT;                                             \
    sortFn(v);                                                                \
    EXPECT_EQ(v, SORTED);                                                     \
}                                                                             \
TEST(Suite, HandlesEmptyArray) {                                              \
    std::vector<int> v;                                                       \
    sortFn(v);                                                                \
    EXPECT_TRUE(v.empty());                                                   \
}                                                                             \
TEST(Suite, HandlesSingleElement) {                                           \
    std::vector<int> v{ 42 };                                                 \
    sortFn(v);                                                                \
    EXPECT_EQ(v, (std::vector<int>{ 42 }));                                   \
}                                                                             \
TEST(Suite, HandlesAlreadySorted) {                                           \
    std::vector<int> v = SORTED;                                              \
    sortFn(v);                                                                \
    EXPECT_EQ(v, SORTED);                                                     \
}                                                                             \
TEST(Suite, HandlesReversedArray) {                                           \
    std::vector<int> v = SORTED;                                              \
    std::reverse(v.begin(), v.end());                                         \
    sortFn(v);                                                                \
    EXPECT_EQ(v, SORTED);                                                     \
}                                                                             \
TEST(Suite, HandlesAllDuplicates) {                                           \
    std::vector<int> v{ 7, 7, 7, 7 };                                         \
    sortFn(v);                                                                \
    EXPECT_EQ(v, (std::vector<int>{ 7, 7, 7, 7 }));                           \
}                                                                             \
TEST(Suite, HandlesNegativeNumbers) {                                         \
    std::vector<int> v{ 3, -1, -7, 0, 5 };                                    \
    sortFn(v);                                                                \
    EXPECT_EQ(v, (std::vector<int>{ -7, -1, 0, 3, 5 }));                      \
}                                                                             \
TEST(Suite, WorksWithDoubles) {                                               \
    std::vector<double> v{ 3.14, 1.41, 2.71, 0.0 };                           \
    sortFn(v);                                                                \
    EXPECT_DOUBLE_EQ(v[0], 0.0);                                              \
    EXPECT_DOUBLE_EQ(v[1], 1.41);                                             \
    EXPECT_DOUBLE_EQ(v[2], 2.71);                                             \
    EXPECT_DOUBLE_EQ(v[3], 3.14);                                             \
}                                                                             \
TEST(Suite, MatchesStdSortOnRandomData) {                                     \
    std::mt19937 gen(12345);                                                  \
    std::uniform_int_distribution<int> dist(-1000, 1000);                     \
    std::vector<int> v(200);                                                  \
    for (auto& x : v) x = dist(gen);                                          \
    std::vector<int> expected = v;                                            \
    std::sort(expected.begin(), expected.end());                              \
    sortFn(v);                                                                \
    EXPECT_EQ(v, expected);                                                   \
}