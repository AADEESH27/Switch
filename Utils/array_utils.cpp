#include "array_utils.h"
#include <vector>

void swap(int *arr, int ind1, int ind2)
{
    int temp = arr[ind1];
    arr[ind1] = arr[ind2];
    arr[ind2] = temp;
    return;
}

void merge(int *arr, int start, int mid, int end)
{
    std::vector<int> temp;
    int i = start;
    int j = mid + 1;
    while (i <= mid && j <= end)
    {
        if (arr[i] <= arr[j])
        {
            temp.push_back(arr[i]);
            i++;
        }
        else
        {
            temp.push_back(arr[j]);
            j++;
        }
    }
    while (i <= mid)
    {
        temp.push_back(arr[i]);
        i++;
    }
    while (j <= end)
    {
        temp.push_back(arr[j]);
        j++;
    }
    for (int i = start; i <= end; i++)
    {
        arr[i] = temp[i - start];
    }
    return;
}

int getPartitionIndex(int *arr, int start, int end)
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