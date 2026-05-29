#include <iostream>
#include "../Utils/array_utils.h"

// Stable: Equal elements are not swapped
// Better for nearly sorted or very small input array as it gets it done in O(n)

void bubbleSort(int *arr, int size);

int main()
{
    int arr[5] = {1, 2, 3, 2, 5};
    bubbleSort(arr, 5);
    for (int num : arr)
    {
        std::cout << num << " ";
    }
    std::cout << "\n";
    return 0;
}

void bubbleSort(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        bool is_swapped = false;
        for (int j = 1; j < size - i; j++)
        {
            if (arr[j] < arr[j - 1])
            {
                swap(arr, j, j - 1);
                is_swapped = true;
            }
        }
        if (!is_swapped)
        {
            std::cout << "Early exit\n";
            return;
        }
    }
    return;
}