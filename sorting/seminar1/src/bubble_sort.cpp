#include "bubble_sort.h"

template <typename T>
void bubbleSort(std::vector<T>& arr) {
    for (size_t i = 0; i < arr.size(); ++i) {
        for (size_t j = 0; j < arr.size() - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

template void bubbleSort<int>(std::vector<int>&);
template void bubbleSort<double>(std::vector<double>&);
template void bubbleSort<float>(std::vector<float>&);
