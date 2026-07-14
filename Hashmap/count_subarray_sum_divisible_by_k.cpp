#include <iostream>
#include <vector>
#include <unordered_map>

int countSubarraysWithSumDivisibleByk(const std::vector<int> &input, int &k);

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
    std::cout << countSubarraysWithSumDivisibleByk(input, k) << "\n";
    return 0;
}

int countSubarraysWithSumDivisibleByk(const std::vector<int> &input, int &k)
{
    std::unordered_map<int, int> mp;
    int pre_sum = 0;
    mp[pre_sum]++;
    int count = 0;
    for (int i = 0; i < input.size(); i++)
    {
        pre_sum += input[i];
        int target = pre_sum % k;
        if (target < 0)
        {
            target += k;
        }
        auto it = mp.find(target);
        if (it != mp.end())
        {
            count += it->second;
        }
        mp[target]++;
    }
    return count;
}