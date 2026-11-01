#include "pch.h"
#include <fstream>
#include <vector>
#include "test_helpers.h"
#include "one_phase_merge_sort.h"

static const std::string kFile = "one_phase_test.bin";

TEST(OnePhaseMergeSort, SortsRegularArray) {
	std::vector<int> a = { 17, 3, 0, 12, 6, 9, 19, 1 };
	std::vector<int> expected = { 0, 1, 3, 6, 9, 12, 17, 19 };
	EXPECT_EQ(sortThroughFile(onePhaseMergeSort<int>, a, kFile), expected);
}

TEST(OnePhaseMergeSort, EmptyFile) {
	std::vector<int> a = {};
	EXPECT_TRUE(sortThroughFile(onePhaseMergeSort<int>, a, kFile).empty());
}

TEST(OnePhaseMergeSort, SingleElement) {
	std::vector<int> a = { 5 };
	std::vector<int> expected = { 5 };
	EXPECT_EQ(sortThroughFile(onePhaseMergeSort<int>, a, kFile), expected);
}

TEST(OnePhaseMergeSort, TwoElements) {
	std::vector<int> a = { 9, 2 };
	std::vector<int> expected = { 2, 9 };
	EXPECT_EQ(sortThroughFile(onePhaseMergeSort<int>, a, kFile), expected);
}

TEST(OnePhaseMergeSort, AlreadySorted) {
	std::vector<int> a = { 1, 2, 3, 4, 5 };
	std::vector<int> expected = { 1, 2, 3, 4, 5 };
	EXPECT_EQ(sortThroughFile(onePhaseMergeSort<int>, a, kFile), expected);
}

TEST(OnePhaseMergeSort, ReverseOrder) {
	std::vector<int> a = { 5, 4, 3, 2, 1 };
	std::vector<int> expected = { 1, 2, 3, 4, 5 };
	EXPECT_EQ(sortThroughFile(onePhaseMergeSort<int>, a, kFile), expected);
}

TEST(OnePhaseMergeSort, DoubleType) {
	std::vector<double> a = { 3.5, -1.2, 0.0, 2.7 };
	std::vector<double> expected = { -1.2, 0.0, 2.7, 3.5 };
	EXPECT_EQ(sortThroughFile(onePhaseMergeSort<double>, a, kFile), expected);
}

TEST(OnePhaseMergeSort, Variant14) {
	std::vector<int> a = { 0, 3, 17, 8, 2, 12, 6, 19 };
	std::vector<int> expected = { 0, 2, 3, 6, 8, 12, 17, 19 };
	EXPECT_EQ(sortThroughFile(onePhaseMergeSort<int>, a, kFile), expected);
}

TEST(OnePhaseMergeSort, WithDuplicates) {
	std::vector<int> a = { 4, 2, 4, 1, 2, 4 };
	std::vector<int> expected = { 1, 2, 2, 4, 4, 4 };
	EXPECT_EQ(sortThroughFile(onePhaseMergeSort<int>, a, kFile), expected);
}

TEST(OnePhaseMergeSort, NotPowerOfTwoSize) {
	// 7 elements: the last runs have different lengths
	std::vector<int> a = { 9, 7, 5, 3, 1, 8, 6 };
	std::vector<int> expected = { 1, 3, 5, 6, 7, 8, 9 };
	EXPECT_EQ(sortThroughFile(onePhaseMergeSort<int>, a, kFile), expected);
}

TEST(OnePhaseMergeSort, TemporaryFilesAreRemoved) {
	std::vector<int> a = { 5, 4, 3, 2, 1 };
	sortThroughFile(onePhaseMergeSort<int>, a, kFile);
	EXPECT_FALSE(std::ifstream(kFile + ".tmp_1").good());
	EXPECT_FALSE(std::ifstream(kFile + ".tmp_2").good());
	EXPECT_FALSE(std::ifstream(kFile + ".tmp_3").good());
	EXPECT_FALSE(std::ifstream(kFile + ".tmp_4").good());
}
