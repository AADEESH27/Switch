#include <iostream>
#include <vector>

void mergeTwoSortedArrayWithoutExtraSpace(std::vector<int> &nums1, int &m, const std::vector<int> &nums2, int &n);

int main()
{
    int m, n;
    std::cin >> m >> n;
    std::vector<int> nums1(m + n);
    std::vector<int> nums2(n);
    for (int i = 0; i < m; i++)
    {
        std::cin >> nums1[i];
    }
    for (int i = 0; i < n; i++)
    {
        std::cin >> nums2[i];
    }
    mergeTwoSortedArrayWithoutExtraSpace(nums1, m, nums2, n);
    for (int i = 0; i < nums1.size(); i++)
    {
        std::cout << nums1[i] << " ";
    }
    std::cout << "\n";
    return 0;
}

void mergeTwoSortedArrayWithoutExtraSpace(std::vector<int> &nums1, int &m, const std::vector<int> &nums2, int &n)
{
    int i = m - 1;
    int j = n - 1;
    int k = (m + n) - 1;
    while (i >= 0 && j >= 0 && k >= 0)
    {
        if (nums1[i] >= nums2[j])
        {
            nums1[k] = nums1[i];
            i--;
            k--;
        }
        else
        {
            nums1[k] = nums2[j];
            j--;
            k--;
        }
    }
    while (i >= 0 && k >= 0)
    {
        nums1[k] = nums1[i];
        i--;
        k--;
    }
    while (j >= 0 && k >= 0)
    {
        nums1[k] = nums2[j];
        j--;
        k--;
    }
    return;
}
