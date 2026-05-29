#include <iostream>
#include "../Utils/array_utils.h"

auto mergeSort(int *arr, int start, int end) -> void;

int main()
{
    int arr[5] = {5, 4, 4, 1, 1};
    int start = 0;
    int end = 4;
    mergeSort(arr, start, end);
    for (int i : arr)
    {
        std::cout << i << "\n";
    }
    return 0;
}

void mergeSort(int *arr, int start, int end)
{
    if (start >= end)
    {
        return;
    }
    int mid = start + (end - start) / 2;
    mergeSort(arr, start, mid);
    mergeSort(arr, mid + 1, end);
    merge(arr, start, mid, end);
    return;
}

// merge function implemented in array_utils and imported using header file