#include "pch.h"
#include <fstream>
#include <vector>
#include "test_helpers.h"
#include "natural_merge_sort.h"

static const std::string kFile = "natural_test.bin";

TEST(NaturalMergeSort, SortsRegularArray) {
	std::vector<int> a = { 17, 3, 0, 12, 6, 9, 19, 1 };
	std::vector<int> expected = { 0, 1, 3, 6, 9, 12, 17, 19 };
	EXPECT_EQ(sortThroughFile(naturalMergeSort<int>, a, kFile), expected);
}

TEST(NaturalMergeSort, EmptyFile) {
	std::vector<int> a = {};
	EXPECT_TRUE(sortThroughFile(naturalMergeSort<int>, a, kFile).empty());
}

TEST(NaturalMergeSort, SingleElement) {
	std::vector<int> a = { 5 };
	std::vector<int> expected = { 5 };
	EXPECT_EQ(sortThroughFile(naturalMergeSort<int>, a, kFile), expected);
}

TEST(NaturalMergeSort, AlreadySorted) {
	std::vector<int> a = { 1, 2, 3, 4, 5 };
	std::vector<int> expected = { 1, 2, 3, 4, 5 };
	EXPECT_EQ(sortThroughFile(naturalMergeSort<int>, a, kFile), expected);
}

TEST(NaturalMergeSort, ReverseOrder) {
	std::vector<int> a = { 5, 4, 3, 2, 1 };
	std::vector<int> expected = { 1, 2, 3, 4, 5 };
	EXPECT_EQ(sortThroughFile(naturalMergeSort<int>, a, kFile), expected);
}

TEST(NaturalMergeSort, DoubleType) {
	std::vector<double> a = { 3.5, -1.2, 0.0, 2.7 };
	std::vector<double> expected = { -1.2, 0.0, 2.7, 3.5 };
	EXPECT_EQ(sortThroughFile(naturalMergeSort<double>, a, kFile), expected);
}

TEST(NaturalMergeSort, Variant14) {
	std::vector<int> a = { 0, 3, 17, 8, 2, 12, 6, 19 };
	std::vector<int> expected = { 0, 2, 3, 6, 8, 12, 17, 19 };
	EXPECT_EQ(sortThroughFile(naturalMergeSort<int>, a, kFile), expected);
}

TEST(NaturalMergeSort, WithDuplicates) {
	std::vector<int> a = { 4, 2, 4, 1, 2, 4 };
	std::vector<int> expected = { 1, 2, 2, 4, 4, 4 };
	EXPECT_EQ(sortThroughFile(naturalMergeSort<int>, a, kFile), expected);
}

TEST(NaturalMergeSort, LongNaturalRuns) {
	// the file already contains several long ascending runs
	std::vector<int> a = { 1, 4, 9, 2, 3, 8, 10, 0, 5, 6, 7 };
	std::vector<int> expected = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	EXPECT_EQ(sortThroughFile(naturalMergeSort<int>, a, kFile), expected);
}

TEST(NaturalMergeSort, TemporaryFilesAreRemoved) {
	std::vector<int> a = { 5, 4, 3, 2, 1 };
	sortThroughFile(naturalMergeSort<int>, a, kFile);
	EXPECT_FALSE(std::ifstream(kFile + ".tmp_b").good());
	EXPECT_FALSE(std::ifstream(kFile + ".tmp_c").good());
}
