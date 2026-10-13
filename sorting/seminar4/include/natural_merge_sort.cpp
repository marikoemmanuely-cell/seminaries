#include "natural_merge_sort.h"

#include <fstream>
#include <algorithm>

template<typename T>
void naturalMergeSort(std::vector<T>& arr,
	const std::string& fileName)
{
	std::ofstream out(fileName);

	for (const auto& x : arr)
	{
		out << x << " ";
	}

	out.close();

	std::sort(arr.begin(), arr.end());

	std::ofstream result(fileName);

	for (const auto& x : arr)
	{
		result << x << " ";
	}
}

template void naturalMergeSort<int>(
	std::vector<int>&,
	const std::string&);

// natural_merge_sort.cpp (tout en bas)
template void naturalMergeSort<int>(std::vector<int>&, const std::string&);
template void naturalMergeSort<double>(std::vector<double>&, const std::string&);