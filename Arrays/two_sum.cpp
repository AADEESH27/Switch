#include <iostream>
#include <vector>
#include <unordered_map>

std::vector<int> towSum(const std::vector<int> &input, int target);

int main()
{
    int size;
    std::cin >> size;
    int target;
    std::cin >> target;
    std::vector<int> input(size);
    for (int i = 0; i < size; i++)
    {
        std::cin >> input[i];
    }
    std::vector<int> result = towSum(input, target);
    for (int i = 0; i < result.size(); i++)
    {
        std::cout << result[i] << " ";
    }
    std::cout << "\n";
    return 0;
}

std::vector<int> towSum(const std::vector<int> &input, int target)
{
    std::unordered_map<int, int> mp;
    for (int i = 0; i < input.size(); i++)
    {
        int complement = target - input[i];
        std::unordered_map<int, int>::iterator it = mp.find(complement);
        if (it != mp.end())
        {
            return {i, mp[complement]};
        }
        else
        {
            mp[input[i]] = i;
        }
    }
    return {};
}