#include <iostream>
#include <algorithm>

auto insertionSort(int *arr, int size) -> void;

int main()
{
    int arr[5] = {5, 4, 3, 2, 1};
    insertionSort(arr, 5);
    for (int i : arr)
    {
        std::cout << i << "\n";
    }
    return 0;
}

void insertionSort(int *arr, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j > 0; j--)
        {
            if (arr[j] < arr[j - 1])
            {
                std::swap(arr[j], arr[j - 1]);
            }
        }
    }
    return;
}