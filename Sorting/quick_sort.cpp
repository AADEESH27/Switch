#include <iostream>
#include <algorithm>

auto quickSort(int *arr, int start, int end) -> void;
auto getPivotIndex(int *arr, int start, int end) -> int;

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
    int pivotElement = arr[start];
    int i = start;
    int j = end;
    while (i < j)
    {
        while (i <= end && arr[i] <= pivotElement)
            i++;
        while (j >= start && arr[j] > pivotElement)
            j--;
        if (i < j)
        {
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[start], arr[j]);
    return j;
}