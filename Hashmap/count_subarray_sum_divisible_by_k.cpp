#include <iostream>
#include <vector>
#include <unordered_map>

int countSubarraySumDivisibleByK(const std::vector<int> &input, int k);

int main()
{
    std::vector<int> input = {3, 1, 4, 1};
    int k = 3;
    std::cout << countSubarraySumDivisibleByK(input, k);
    return 0;
}

int countSubarraySumDivisibleByK(const std::vector<int> &input, int k)
{
    std::unordered_map<int, int> remainderFromKMap;
    remainderFromKMap[0] = 1;
    int count = 0;
    int pre_sum = 0;
    for (int i = 0; i < input.size(); i++)
    {
        pre_sum += input[i];
        int question_from_map = pre_sum % k;
        if (question_from_map < 0)
        {
            question_from_map += k;
        }
        if (remainderFromKMap.find(question_from_map) != remainderFromKMap.end())
        {
            count += remainderFromKMap[question_from_map];
        }
        remainderFromKMap[question_from_map]++;
    }
    return count;
}