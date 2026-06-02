#include <iostream>
#include "../Utils/array_utils.h"

void bigElementsBubbleUpSort(int *arr, int size);
void selectionMinOrMaxSort(int *arr, int size);
void insertionAtSortedLeftPartSort(int *arr, int size);

int main()
{
    int arr[5] = {7, 1, 4, 3, 2};
    int size = 5;
    return 0;
}

void bigElementsBubbleUpSort(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        bool is_swapped = false;
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                is_swapped = true;
                swap(arr, j, j + 1);
            }
        }
        if (!is_swapped)
            return;
    }
    return;
}

void selectionMinOrMaxSort(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        int min_idx = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[min_idx])
            {
                min_idx = j;
            }
        }
        swap(arr, i, min_idx);
    }
    return;
}

void insertionAtSortedLeftPartSort(int *arr, int size)
{
    for (int i = 1; i < size; i++)
    {
        for (int j = i; j > 0; j--)
        {
            if (arr[j] < arr[j - 1])
            {
                swap(arr, j, j - 1);
            }
            else
            {
                break;
            }
        }
    }
    return;
}