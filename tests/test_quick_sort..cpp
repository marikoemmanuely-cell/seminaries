// test_quick_sort.cpp
#include "quick_sort.h"
#include "sort_test_common.h"

template <typename T>
void quickSortAdapter(std::vector<T>& v) {
    quickSort(v, 0, static_cast<int>(v.size()) - 1);
}

SORT_TEST_SUITE(QuickSort, quickSortAdapter)