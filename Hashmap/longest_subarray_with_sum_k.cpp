#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

int calculateLengthOfLongestSubarrayWithSumK(const std::vector<int> &input, int k);
int main()
{
    std::vector<int> input = {10, 5, 2, 7, 1, 9};
    int k = 15;
    std::cout << calculateLengthOfLongestSubarrayWithSumK(input, k);
    return 0;
}

int calculateLengthOfLongestSubarrayWithSumK(const std::vector<int> &input, int k)
{
    int max_length = 0;
    std::unordered_map<int, int> prefixSumComplimentKMap;
    int pre_sum = 0;
    prefixSumComplimentKMap[0] = -1;
    for (int i = 0; i < input.size(); i++)
    {
        pre_sum += input[i];
        int question_from_map = pre_sum - k;
        if (prefixSumComplimentKMap.find(question_from_map) != prefixSumComplimentKMap.end())
        {
            int length = i - prefixSumComplimentKMap[question_from_map];
            max_length = std::max(max_length, length);
        }
        if (prefixSumComplimentKMap.find(pre_sum) == prefixSumComplimentKMap.end())
        {
            prefixSumComplimentKMap[pre_sum] = i;
        }
    }
    return max_length;
}