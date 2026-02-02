#include <iostream>
#include <algorithm>

auto selectionSort(int *arr, int size) -> void;

int main()
{
    int arr[5] = {5, 4, 3, 2, 1};
    selectionSort(arr, 5);
    for (int i : arr)
    {
        std::cout << i << "\n";
    }
    return 0;
}

void selectionSort(int *arr, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int min_idx = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[i])
            {
                min_idx = j;
            }
        }
        std::swap(arr[i], arr[min_idx]);
    }
    return;
}