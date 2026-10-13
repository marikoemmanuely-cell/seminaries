#include "optimized_bubble_sort.h"

template <typename T>
void optimizedBubbleSort(std::vector<T>& arr) {
    bool swapped = true;

    for (size_t i = 0; i < arr.size() && swapped; ++i) {
        swapped = false;

        for (size_t j = 0; j < arr.size() - 1 - i; ++j) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
    }
}

template void optimizedBubbleSort<int>(std::vector<int>&);
template void optimizedBubbleSort<double>(std::vector<double>&);
template void optimizedBubbleSort<float>(std::vector<float>&);
