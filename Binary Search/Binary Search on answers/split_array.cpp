#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

int largestSubarraySumMinimized(const std::vector<int> &input, const int &k);

int largestElement(const std::vector<int> &input);

long long sumOfAllElements(const std::vector<int> &input);

bool checkIfSumLimitEnough(const std::vector<int> &input, const int &k, long long limit);

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
    std::cout << largestSubarraySumMinimized(input, k) << "\n";
    return 0;
}

int largestSubarraySumMinimized(const std::vector<int> &input, const int &k)
{
    int ans;
    int left = largestElement(input);
    long long right = sumOfAllElements(input);
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        bool is_sum_enough = checkIfSumLimitEnough(input, k, mid);
        if (is_sum_enough)
        {
            ans = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return ans;
}

int largestElement(const std::vector<int> &input)
{
    int max_ele = INT_MIN;
    for (int i = 0; i < input.size(); i++)
    {
        if (input[i] > max_ele)
        {
            max_ele = input[i];
        }
    }
    return max_ele;
}

long long sumOfAllElements(const std::vector<int> &input)
{
    long long sum = 0;
    for (int i = 0; i < input.size(); i++)
    {
        sum += input[i];
    }
    return sum;
}

bool checkIfSumLimitEnough(const std::vector<int> &input, const int &k, long long limit)
{
    long long sum = input[0];
    int count = 1;
    for (int i = 1; i < input.size(); i++)
    {
        if (sum + input[i] > limit)
        {
            count++;
            sum = input[i];
        }
        else
        {
            sum += input[i];
        }
        if (count > k)
        {
            return false;
        }
    }

    // Greedy gives the minimum number of partitions needed for a given limit. If this minimum is ≤ k, we can always split existing partitions further to obtain exactly k partitions (or fewer if the problem allows at most k). Therefore, the feasibility check is count <= k, not count == k.
    if (count > k)
    {
        return false;
    }
    return true;
}