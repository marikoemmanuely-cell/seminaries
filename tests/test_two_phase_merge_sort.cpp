
#include <cstdio>
#include <string>
#include <vector>
#include "two_phase_merge_sort.h"
#include "sort_test_common.h"

// Adaptateur : ajoute le nom du fichier temporaire et le supprime ensuite
template <typename T>
void twoPhaseAdapter(std::vector<T>& v) {
    const std::string tmp = "tmp_two_phase_test.txt";
    twoPhaseMergeSort(v, tmp);
    std::remove(tmp.c_str());
}

SORT_TEST_SUITE(TwoPhaseMergeSort, twoPhaseAdapter)
