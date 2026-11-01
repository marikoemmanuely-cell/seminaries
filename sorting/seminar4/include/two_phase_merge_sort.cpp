#include "two_phase_merge_sort.h"

#include <fstream>
#include <algorithm>

template<typename T>
void twoPhaseMergeSort(std::vector<T>& arr,
	const std::string& fileName)
{
	std::ofstream out(fileName);

	for (const auto& x : arr)
	{   
		out << x << " ";
	}

	out.close();

	std::ifstream in(fileName);

	arr.clear();

	T value;

	while (in >> value)
	{
		arr.push_back(value);
	}

	in.close();

	std::sort(arr.begin(), arr.end());

	std::ofstream result(fileName);

	for (const auto& x : arr)
	{
		result << x << " ";
	}
}

// two_phase_merge_sort.cpp (tout en bas)
template void twoPhaseMergeSort<int>(std::vector<int>&, const std::string&);
template void twoPhaseMergeSort<double>(std::vector<double>&, const std::string&);