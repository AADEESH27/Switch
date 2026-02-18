#include <iostream>
#include <algorithm>

// Stable: Equal elements are not swapped
// Better for nearly sorted or very small input array as it gets it done in O(n)

void bubbleSort(int *arr, int size);

int main()
{
    int arr[5] = {5, 4, 3, 2, 1};
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
    for (int i = 0; i < size - 1; i++)
    {
        bool is_swapped = false;
        for (int j = 1; j < size - i; j++)
        {
            if (arr[j] < arr[j - 1])
            {
                is_swapped = true;
                std::swap(arr[j], arr[j - 1]);
            }
        }
        if (!is_swapped)
        {
            break;
        }
    }
}
