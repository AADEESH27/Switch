/*
Given an array nums of n integers and an integer k, return the total number of jumps needed in the array.

An element nums[i] needs to jump another element nums[j] if:

0 <= i < j <= n-1
nums[i] + k < nums[j]
*/

#include <iostream>
#include <vector>

int countJumps(std::vector<int> &input, const int &k);
void mergeSort(std::vector<int> &input, int start, int end, const int &k, int &count);
void merge(std::vector<int> &input, int start, int mid, int end, const int &k, int &count);

int main()
{
    int size;
    std::cin >> size;
    std::vector<int> input(size);
    for (int i = 0; i < size; i++)
    {
        std::cin >> input[i];
    }
    int k;
    std::cin >> k;
    std::cout << countJumps(input, k) << "\n";
    return 0;
}

int countJumps(std::vector<int> &input, const int &k)
{
    int count = 0;
    mergeSort(input, 0, input.size() - 1, k, count);
    return count;
}

void mergeSort(std::vector<int> &input, int start, int end, const int &k, int &count)
{
    if (start >= end)
    {
        return;
    }
    int mid = start + (end - start) / 2;
    mergeSort(input, start, mid, k, count);
    mergeSort(input, mid + 1, end, k, count);
    merge(input, start, mid, end, k, count);
    return;
}

void merge(std::vector<int> &input, int start, int mid, int end, const int &k, int &count)
{
    std::vector<int> temp;
    int i = start;
    int j = mid + 1;
    while (i <= mid && j <= end)
    {
        if (input[i] < input[j] - k)
        {
            count += end - j + 1;
            i++;
        }
        else
        {
            j++;
        }
    }
    i = start;
    j = mid + 1;
    while (i <= mid && j <= end)
    {
        if (input[i] <= input[j])
        {
            temp.push_back(input[i]);
            i++;
        }
        else
        {
            temp.push_back(input[j]);
            j++;
        }
    }
    while (i <= mid)
    {
        temp.push_back(input[i]);
        i++;
    }
    while (j <= end)
    {
        temp.push_back(input[j]);
        j++;
    }
    for (int i = start; i <= end; i++)
    {
        input[i] = temp[i - start];
    }
    return;
}