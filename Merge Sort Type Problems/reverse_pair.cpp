/*
0 <= i < j < nums.length

nums[i] > 2 * nums[j]

Example 1

Input: nums = [6, 4, 1, 2, 7]

Output: 3

Explanation:

The reverse pairs are:

(0, 2) : nums[0] = 6, nums[2] = 1, 6 > 2 * 1

(0, 3) : nums[0] = 6, nums[3] = 2, 6 > 2 * 2

(1, 2) : nums[1] = 4, nums[2] = 1, 4 > 2 * 1

Observation: Whenever you have to find pairs/count any two elements nums[i] and nums[j] where the constraint is i < j, think of merge sort.
*/

#include <iostream>
#include <vector>

auto mergeSort(std::vector<int> &nums, int start, int end, int &count) -> void;
auto merge(std::vector<int> &nums, int start, int mid, int end, int &count) -> void;

int main()
{
    std::vector<int> nums = {6, 4, 1, 2, 7};
    int count = 0;
    mergeSort(nums, 0, nums.size() - 1, count);
    std::cout << count << "\n";
    for (int x : nums)
    {
        std::cout << x << " ";
    }
    return 0;
}

void mergeSort(std::vector<int> &nums, int start, int end, int &count)
{
    if (start >= end)
    {
        return;
    }
    int mid = start + (end - start) / 2;
    mergeSort(nums, start, mid, count);
    mergeSort(nums, mid + 1, end, count);
    merge(nums, start, mid, end, count);
    return;
}

void merge(std::vector<int> &nums, int start, int mid, int end, int &count)
{
    int i = start;
    int j = mid + 1;
    std::vector<int> temp;
    while (i <= mid && j <= end)
    {
        if (nums[i] > 2 * nums[j])
        {
            count += mid - i + 1;
            j++;
        }
        else
        {
            i++;
        }
    }
    i = start;
    j = mid + 1;
    while (i <= mid && j <= end)
    {
        if (nums[i] <= nums[j])
        {
            temp.push_back(nums[i]);
            i++;
        }
        else
        {
            temp.push_back(nums[j]);
            j++;
        }
    }
    while (i <= mid)
    {
        temp.push_back(nums[i]);
        i++;
    }
    while (j <= end)
    {
        temp.push_back(nums[j]);
        j++;
    }
    for (int i = start; i <= end; i++)
    {
        nums[i] = temp[i - start];
    }
    return;
}