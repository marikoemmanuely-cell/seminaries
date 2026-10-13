#include "selection_sort.h"

template <typename T>
void selectionSort(std::vector<T>& arr) {
    for (size_t i = 0; i < arr.size(); ++i) {
        size_t minIndex = i;

        for (size_t j = i + 1; j < arr.size(); ++j) {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }

        std::swap(arr[i], arr[minIndex]);
    }
}

template void selectionSort<int>(std::vector<int>&);
template void selectionSort<double>(std::vector<double>&);
template void selectionSort<float>(std::vector<float>&);
