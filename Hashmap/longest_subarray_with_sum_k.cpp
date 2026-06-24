#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>
#include <algorithm>

int longestLengthOfSubarrayWithSumK(const std::vector<int> &input, int &k);
int countOfSubarrayWithSumK(const std::vector<int> &input, int &k);

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
    std::cout << longestLengthOfSubarrayWithSumK(input, k);
    return 0;
}

int longestLengthOfSubarrayWithSumK(const std::vector<int> &input, int &k)
{
    std::unordered_map<int, int> map;
    map[0] = -1;
    int max_length = INT_MIN;
    int prefix_sum = 0;
    for (int i = 0; i < input.size(); i++)
    {
        prefix_sum += input[i];
        auto it = map.find(prefix_sum - k);
        if (it != map.end())
        {
            max_length = std::max(max_length, (i - it->second));
        }
        if (map.find(prefix_sum) == map.end())
        {
            map[prefix_sum] = i;
        }
    }
    return max_length == INT_MIN ? 0 : max_length;
}

int countOfSubarrayWithSumK(const std::vector<int> &input, int &k)
{
    std::unordered_map<int, int> map;
    map[0]++;
    int count = 0;
    int prefix_sum = 0;
    for (int i = 0; i < input.size(); i++)
    {
        prefix_sum += input[i];
        auto it = map.find(prefix_sum - k);
        if (it != map.end())
        {
            count += it->second;
        }
        map[prefix_sum]++;
    }
    return count;
}