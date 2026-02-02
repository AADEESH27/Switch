#include <iostream>
#include <algorithm>

auto bubbleSort(int *arr, int size) -> void;

int main()
{
    int arr[5] = {5, 4, 3, 2, 1};
    bubbleSort(arr, 5);
    for (int i : arr)
    {
        std::cout << i << "\n";
    }
    return 0;
}

void bubbleSort(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        bool is_swapped = false;
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                std::swap(arr[j], arr[j + 1]);
                is_swapped = true;
            }
        }
        if (!is_swapped)
        {
            break;
        }
    }
    return;
}