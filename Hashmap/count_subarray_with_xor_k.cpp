#include <iostream>
#include <vector>
#include <unordered_map>

int countSubarrayWithXORk(const std::vector<int> &input, int &k);

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
    int result = countSubarrayWithXORk(input, k);
    std::cout << result << "\n";
    return 0;
}

int countSubarrayWithXORk(const std::vector<int> &input, int &k)
{
    std::unordered_map<int, int> map;
    int count = 0;
    int pre_xor = 0;
    map[pre_xor]++;
    for (int i = 0; i < input.size(); i++)
    {
        pre_xor ^= input[i];
        int target = pre_xor ^ k;
        auto it = map.find(target);
        if (it != map.end())
        {
            count += it->second;
        }
        map[pre_xor]++;
    }
    return count;
}