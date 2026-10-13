
#include <cstdio>
#include <string>
#include <vector>
#include "one_phase_merge_sort.h"
#include "sort_test_common.h"

template <typename T>
void onePhaseAdapter(std::vector<T>& v) {
    const std::string tmp = "tmp_one_phase_test.txt";
    onePhaseMergeSort(v, tmp);
    std::remove(tmp.c_str());
}

SORT_TEST_SUITE(OnePhaseMergeSort, onePhaseAdapter)
