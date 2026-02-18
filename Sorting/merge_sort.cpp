#include <iostream>
#include <vector>

// Stable sorting algorithm
auto mergerSort(int *arr, int start, int end) -> void;
auto mergeSorted(int *arr, int start, int mid, int end) -> void;

int main()
{
    int arr[5] = {4, 3, 2, 5, 1};
    int start = 0;
    int end = 4;
    mergerSort(arr, start, end);
    for (int i : arr)
    {
        std::cout << i << "\n";
    }
    return 0;
}

void mergerSort(int *arr, int start, int end)
{
    if (start >= end)
    {
        return;
    }
    int mid = start + (end - start) / 2;
    mergerSort(arr, start, mid);
    mergerSort(arr, mid + 1, end);
    mergeSorted(arr, start, mid, end);
}

void mergeSorted(int *arr, int start, int mid, int end)
{
    int s_f = start;
    int e_f = mid;
    int s_s = mid + 1;
    int e_s = end;
    std::vector<int> temp_result;
    while (s_f <= e_f && s_s <= e_s)
    {
        if (arr[s_f] <= arr[s_s])
        {
            temp_result.push_back(arr[s_f]);
            s_f++;
        }
        else
        {
            temp_result.push_back(arr[s_s]);
            s_s++;
        }
    }
    while (s_f <= e_f)
    {
        temp_result.push_back(arr[s_f]);
        s_f++;
    }
    while (s_s <= e_s)
    {
        temp_result.push_back(arr[s_s]);
        s_s++;
    }
    for (int i = start; i <= end; i++)
    {
        arr[i] = temp_result[i - start];
    }
    return;
}