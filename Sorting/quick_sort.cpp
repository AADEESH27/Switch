#include <iostream>
#include "../Utils/array_utils.h"

auto quickSort(int *arr, int start, int end) -> void;
int getPivotIndex(int *arr, int start, int end);

int main()
{
    int arr[5] = {7, 4, 1, 5, 3};
    int start = 0;
    int end = 4;
    quickSort(arr, start, end);
    for (int i : arr)
    {
        std::cout << i << "\n";
    }
    return 0;
}

void quickSort(int *arr, int start, int end)
{
    if (start >= end)
    {
        return;
    }
    int pivotIndex = getPivotIndex(arr, start, end);
    quickSort(arr, start, pivotIndex - 1);
    quickSort(arr, pivotIndex + 1, end);
    return;
}

int getPivotIndex(int *arr, int start, int end)
{
    int pivot = arr[start];
    int i = start;
    int j = end;
    while (i < j)
    {
        while (i <= end && arr[i] <= pivot)
        {
            i++;
        }
        while (j >= start && arr[j] > pivot)
        {
            j--;
        }
        if (i < j)
        {
            swap(arr, i, j);
        }
    }
    swap(arr, start, j);
    return j;
}