/*#include <gtest/gtest.h>
#include "../seminar1/insertion_sort.h"    
#include <vector>

TEST(InsertionSort, SortsRandomArray) {
    std::vector<int> v{ 0, 3, 17, 8, 2, 12, 6, 19 };
    insertionSort(v);
    EXPECT_EQ(v, (std::vector<int>{0, 2, 3, 6, 8, 12, 17, 19}));
}

TEST(InsertionSort, HandlesEmptyArray) {
    std::vector<int> v;
    insertionSort(v);
    EXPECT_TRUE(v.empty());
}

TEST(InsertionSort, HandlesSingleElement) {
    std::vector<int> v{ 42 };
    insertionSort(v);
    EXPECT_EQ(v, (std::vector<int>{42}));
}

TEST(InsertionSort, HandlesAlreadySorted) {
    std::vector<int> v{ 0, 3, 17, 8, 2, 12, 6, 19 };
    insertionSort(v);
    EXPECT_EQ(v, (std::vector<int>{0, 2, 3, 6, 8, 12, 17, 19}));
}

TEST(InsertionSort, HandlesReversedArray) {
    std::vector<int> v{ 0, 3, 17, 8, 2, 12, 6, 19 };
    insertionSort(v);
    EXPECT_EQ(v, (std::vector<int>{0, 1, 2, 3, 4}));
}

TEST(InsertionSort, WorksWithDoubles) {
    std::vector<double> v{ 3.14, 1.41, 2.71, 0.0 };
    insertionSort(v);
    EXPECT_DOUBLE_EQ(v[0], 0.0);
    EXPECT_DOUBLE_EQ(v[1], 1.41);
    EXPECT_DOUBLE_EQ(v[2], 2.71);
    EXPECT_DOUBLE_EQ(v[3], 3.14);
}

TEST(InsertionSort, HandlesAllDuplicates) {
    std::vector<int> v{ 7, 7, 7, 7 };
    insertionSort(v);
    EXPECT_EQ(v, (std::vector<int>{7, 7, 7, 7}));
}*/