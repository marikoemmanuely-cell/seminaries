#include "pch.h"
#include <fstream>
#include <vector>
#include "test_helpers.h"
#include "two_phase_merge_sort.h"

static const std::string kFile = "two_phase_test.bin";
//life
TEST(TwoPhaseMergeSort, SortsRegularArray) {
	std::vector<int> a = { 17, 3, 0, 12, 6, 9, 19, 1 };
	std::vector<int> expected = { 0, 1, 3, 6, 9, 12, 17, 19 };
	EXPECT_EQ(sortThroughFile(twoPhaseMergeSort<int>, a, kFile), expected);
}

TEST(TwoPhaseMergeSort, EmptyFile) {
	std::vector<int> a = {};
	EXPECT_TRUE(sortThroughFile(twoPhaseMergeSort<int>, a, kFile).empty());
}

TEST(TwoPhaseMergeSort, SingleElement) {
	std::vector<int> a = { 5 };
	std::vector<int> expected = { 5 };
	EXPECT_EQ(sortThroughFile(twoPhaseMergeSort<int>, a, kFile), expected);
}

TEST(TwoPhaseMergeSort, AlreadySorted) {
	std::vector<int> a = { 1, 2, 3, 4, 5 };
	std::vector<int> expected = { 1, 2, 3, 4, 5 };
	EXPECT_EQ(sortThroughFile(twoPhaseMergeSort<int>, a, kFile), expected);
}

TEST(TwoPhaseMergeSort, ReverseOrder) {
	std::vector<int> a = { 5, 4, 3, 2, 1 };
	std::vector<int> expected = { 1, 2, 3, 4, 5 };
	EXPECT_EQ(sortThroughFile(twoPhaseMergeSort<int>, a, kFile), expected);
}

TEST(TwoPhaseMergeSort, DoubleType) {
	std::vector<double> a = { 3.5, -1.2, 0.0, 2.7 };
	std::vector<double> expected = { -1.2, 0.0, 2.7, 3.5 };
	EXPECT_EQ(sortThroughFile(twoPhaseMergeSort<double>, a, kFile), expected);
}

TEST(TwoPhaseMergeSort, Variant14) {
	std::vector<int> a = { 0, 3, 17, 8, 2, 12, 6, 19 };
	std::vector<int> expected = { 0, 2, 3, 6, 8, 12, 17, 19 };
	EXPECT_EQ(sortThroughFile(twoPhaseMergeSort<int>, a, kFile), expected);
}

TEST(TwoPhaseMergeSort, WithDuplicates) {
	std::vector<int> a = { 4, 2, 4, 1, 2, 4 };
	std::vector<int> expected = { 1, 2, 2, 4, 4, 4 };
	EXPECT_EQ(sortThroughFile(twoPhaseMergeSort<int>, a, kFile), expected);
}

TEST(TwoPhaseMergeSort, NotPowerOfTwoSize) {
	// 7 elements: the last runs have different lengths
	std::vector<int> a = { 9, 7, 5, 3, 1, 8, 6 };
	std::vector<int> expected = { 1, 3, 5, 6, 7, 8, 9 };
	EXPECT_EQ(sortThroughFile(twoPhaseMergeSort<int>, a, kFile), expected);
}

TEST(TwoPhaseMergeSort, TemporaryFilesAreRemoved) {
	std::vector<int> a = { 5, 4, 3, 2, 1 };
	sortThroughFile(twoPhaseMergeSort<int>, a, kFile);
	EXPECT_FALSE(std::ifstream(kFile + ".tmp_b").good());
	EXPECT_FALSE(std::ifstream(kFile + ".tmp_c").good());
}
