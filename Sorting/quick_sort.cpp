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
    int left = start + 1;
    int right = end;
    while (left <= right)
    {
        while (left <= end && arr[left] <= pivot)
        {
            left++;
        }
        while (right >= start + 1 && arr[right] > pivot)
        {
            right--;
        }
        if (left < right)
        {
            swap(arr, left, right);
        }
    }
    swap(arr, start, right);
    return right;
}