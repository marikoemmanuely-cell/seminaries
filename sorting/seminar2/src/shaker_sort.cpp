#include "shaker_sort.h"
#include <utility>

template<typename T>
void shakerSort(std::vector<T>& arr)
{
    if (arr.empty())
        return;

    int left = 0;
    int right = static_cast<int>(arr.size()) - 1;

    while (left < right)
    {
        for (int i = left; i < right; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                std::swap(arr[i], arr[i + 1]);
            }
        }

        right--;

        for (int i = right; i > left; i--)
        {
            if (arr[i] < arr[i - 1])
            {
                std::swap(arr[i], arr[i - 1]);
            }
        }

        left++;
    }
}

template void shakerSort<int>(std::vector<int>&);
template void shakerSort<double>(std::vector<double>&);
