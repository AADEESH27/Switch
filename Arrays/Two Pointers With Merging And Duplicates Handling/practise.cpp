/*
Drill Set A: Two sorted arrays (MUST MASTER)

    Union of two sorted arrays (distinct) - done

    Intersection of two sorted arrays (distinct) - done

    Symmetric difference (couldn't do optimally in 31st Jan contest) - done

    Merge two sorted arrays without duplicates

    Count common elements

Drill Set B: Duplicate handling

    Remove duplicates from sorted array

    Keep at most 2 duplicates

    Unique elements in sorted array

Drill Set C: Pointer logic under pressure

    Given two sorted arrays, find pair with given sum

    Count pairs with sum less than K

    Find median of two sorted arrays (hard)
*/

#include <iostream>
#include <vector>

auto union_of_two_sorted_arrays_distinct(std::vector<int> &nums1, std::vector<int> &nums2) -> void;
auto intersection_of_two_sorted_arrays_distinct(std::vector<int> &nums1, std::vector<int> &nums2) -> void;
auto set_difference_of_two_sorted_arrays_distinct(std::vector<int> &nums1, std::vector<int> &nums2) -> void;

int main()
{
    std::vector<int> nums1 = {1, 2, 6, 6};
    std::vector<int> nums2 = {-2, 2, 3, 4, 6};
    union_of_two_sorted_arrays_distinct(nums1, nums2);
    intersection_of_two_sorted_arrays_distinct(nums1, nums2);
    set_difference_of_two_sorted_arrays_distinct(nums1, nums2);
    return 0;
}

void union_of_two_sorted_arrays_distinct(std::vector<int> &nums1, std::vector<int> &nums2)
{
    /*
        Skipping duplicates improves the time for checking each element with temp.back() when the duplicate block is too large.
    */

    std::vector<int> temp;
    int i = 0;
    int j = 0;

    while (i < nums1.size() && j < nums2.size())
    {
        if (nums1[i] <= nums2[j])
        {
            if (temp.size() == 0 || temp.back() != nums1[i])
            {
                temp.push_back(nums1[i]);
            }
            int val_to_skip = nums1[i];
            while (i < nums1.size() && nums1[i] == val_to_skip)
            {
                i++;
            }
        }
        else
        {
            if (temp.size() == 0 || temp.back() != nums2[j])
            {
                temp.push_back(nums2[j]);
            }
            int val_to_skip = nums2[j];
            while (j < nums2.size() && nums2[j] == val_to_skip)
            {
                j++;
            }
        }
    }
    while (i < nums1.size())
    {
        if (temp.size() == 0 || temp.back() != nums1[i])
        {
            temp.push_back(nums1[i]);
        }
        int val_to_skip = nums1[i];
        while (i < nums1.size() && nums1[i] == val_to_skip)
        {
            i++;
        }
    }
    while (j < nums2.size())
    {
        if (temp.size() == 0 || temp.back() != nums2[j])
        {
            temp.push_back(nums2[j]);
        }
        int val_to_skip = nums2[j];
        while (j < nums2.size() && nums2[j] == val_to_skip)
        {
            j++;
        }
    }
    for (int i = 0; i < temp.size(); i++)
    {
        std::cout << temp[i] << " ";
    }
    std::cout << "\n";
    return;
}

void intersection_of_two_sorted_arrays_distinct(std::vector<int> &nums1, std::vector<int> &nums2)
{
    std::vector<int> temp;
    int i = 0;
    int j = 0;

    while (i < nums1.size() && j < nums2.size())
    {
        if (nums1[i] == nums2[j])
        {
            if (temp.size() == 0 || temp.back() != nums1[i])
            {

                temp.push_back(nums1[i]);
            }
            int value_to_skip = nums1[i];
            while (i < nums1.size() && nums1[i] == value_to_skip)
            {
                i++;
            }
            while (j < nums2.size() && nums2[j] == value_to_skip)
            {
                j++;
            }
        }
        else if (nums1[i] < nums2[j])
        {
            int value_to_skip = nums1[i];
            while (i < nums1.size() && nums1[i] == value_to_skip)
            {
                i++;
            }
        }
        else
        {
            int value_to_skip = nums2[j];
            while (j < nums2.size() && nums2[j] == value_to_skip)
            {
                j++;
            }
        }
    }
    for (int i = 0; i < temp.size(); i++)
    {
        std::cout << temp[i] << " ";
    }
    std::cout << "\n";
    return;
}

void set_difference_of_two_sorted_arrays_distinct(std::vector<int> &nums1, std::vector<int> &nums2)
{
    std::vector<int> temp;
    int i = 0;
    int j = 0;
    while (i < nums1.size() && j < nums2.size())
    {
        if (nums1[i] == nums2[j])
        {
            int value_to_skip = nums1[i];
            while (i < nums1.size() && nums1[i] == value_to_skip)
            {
                i++;
            }
            while (j < nums2.size() && nums2[j] == value_to_skip)
            {
                j++;
            }
        }
        else if (nums1[i] < nums2[j])
        {
            if (temp.size() == 0 || temp.back() != nums1[i])
            {
                temp.push_back(nums1[i]);
            }
            int value_to_skip = nums1[i];
            while (i < nums1.size() && nums1[i] == value_to_skip)
            {
                i++;
            }
        }
        else
        {
            if (temp.size() == 0 || temp.back() != nums2[j])
            {
                temp.push_back(nums2[j]);
            }
            int value_to_skip = nums2[j];
            while (j < nums2.size() && nums2[j] == value_to_skip)
            {
                j++;
            }
        }
    }
    while (i < nums1.size())
    {
        if (temp.size() == 0 || temp.back() != nums1[i])
        {
            temp.push_back(nums1[i]);
        }
        int value_to_skip = nums1[i];
        while (i < nums1.size() && nums1[i] == value_to_skip)
        {
            i++;
        }
    }
    while (j < nums2.size())
    {
        if (temp.size() == 0 || temp.back() != nums2[j])
        {
            temp.push_back(nums2[j]);
        }
        int value_to_skip = nums2[j];
        while (j < nums2.size() && nums2[j] == value_to_skip)
        {
            j++;
        }
    }
    for (int i = 0; i < temp.size(); i++)
    {
        std::cout << temp[i] << " ";
    }
    std::cout << "\n";
    return;
}