#include "one_phase_merge_sort.h"

#include <fstream>
#include <algorithm>

template<typename T>
void onePhaseMergeSort(std::vector<T>& arr,
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

template void onePhaseMergeSort<int>(
	std::vector<int>&,
	const std::string&);

// one_phase_merge_sort.cpp (tout en bas)
template void onePhaseMergeSort<int>(std::vector<int>&, const std::string&);
template void onePhaseMergeSort<double>(std::vector<double>&, const std::string&);
