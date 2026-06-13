#include <iostream>
#include <vector>

std::vector<int> setDifferenceOfTwoSortedArrays(const std::vector<int> &nums1, const std::vector<int> nums2);

int main()
{
    int m, n;
    std::cin >> m >> n;
    std::vector<int> nums1(m), nums2(n);
    for (int i = 0; i < m; i++)
    {
        std::cin >> nums1[i];
    }
    for (int i = 0; i < n; i++)
    {
        std::cin >> nums2[i];
    }
    std::vector<int> result = setDifferenceOfTwoSortedArrays(nums1, nums2);
    for (int i = 0; i < result.size(); i++)
    {
        std::cout << result[i] << " ";
    }
    std::cout << "\n";
    return 0;
}

std::vector<int> setDifferenceOfTwoSortedArrays(const std::vector<int> &nums1, const std::vector<int> nums2)
{
    std::vector<int> result;
    int i = 0;
    int j = 0;
    while (i < nums1.size() && j < nums2.size())
    {
        if (nums1[i] == nums2[j])
        {
            i++;
            while (i < nums1.size() && nums1[i] == nums1[i - 1])
            {
                i++;
            }
            j++;
            while (j < nums2.size() && nums2[j] == nums2[j - 1])
            {
                j++;
            }
        }
        else
        {
            if (nums1[i] < nums2[j])
            {
                if (result.size() == 0)
                {
                    result.push_back(nums1[i]);
                    i++;
                }
                else if (result.size() >= 1 && result.back() != nums1[i])
                {
                    result.push_back(nums1[i]);
                    i++;
                }
                else
                {
                    i++;
                }
            }
            else
            {
                if (result.size() == 0)
                {
                    result.push_back(nums2[j]);
                    j++;
                }
                else if (result.size() >= 1 && result.back() != nums2[j])
                {
                    result.push_back(nums2[j]);
                    j++;
                }
                else
                {
                    j++;
                }
            }
        }
    }
    while (i < nums1.size())
    {
        if (result.size() == 0)
        {
            result.push_back(nums1[i]);
            i++;
        }
        else if (result.size() >= 1 && result.back() != nums1[i])
        {
            result.push_back(nums1[i]);
            i++;
        }
        else
        {
            i++;
        }
    }
    while (j < nums2.size())
    {
        if (result.size() == 0)
        {
            result.push_back(nums2[j]);
            j++;
        }
        else if (result.size() >= 1 && result.back() != nums2[j])
        {
            result.push_back(nums2[j]);
            j++;
        }
        else
        {
            j++;
        }
    }
    return result;
}