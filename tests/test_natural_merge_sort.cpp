
#include <cstdio>
#include <string>
#include <vector>
#include "natural_merge_sort.h"
#include "sort_test_common.h"

template <typename T>
void naturalAdapter(std::vector<T>& v) {
    const std::string tmp = "tmp_natural_test.txt";
    naturalMergeSort(v, tmp);
    std::remove(tmp.c_str());
}

SORT_TEST_SUITE(NaturalMergeSort, naturalAdapter)

// Test propre au tri naturel : séries croissantes déjà présentes
TEST(NaturalMergeSort, MergesExistingRuns) {
    std::vector<int> v{ 1, 4, 9, 2, 5, 8, 3, 6, 7 };   // [1 4 9] [2 5 8] [3 6 7]
    naturalAdapter(v);
    EXPECT_EQ(v, (std::vector<int>{ 1, 2, 3, 4, 5, 6, 7, 8, 9 }));
}

// fin de natural_merge_sort.cpp
template void naturalMergeSort<int>(std::vector<int>&, const std::string&);
template void naturalMergeSort<double>(std::vector<double>&, const std::string&);