#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <climits>

int longestConsecutiveSequence(std::vector<int> &input);
int lengthOfSequenceFromStart(int &start, std::unordered_map<int, int> &map);

int main()
{
    int size;
    std::cin >> size;
    std::vector<int> input(size);
    for (int i = 0; i < size; i++)
    {
        std::cin >> input[i];
    }
    std::cout << longestConsecutiveSequence(input);
    return 0;
}

int longestConsecutiveSequence(std::vector<int> &input)
{
    // tc O(nlogn + n) sc O(1)
    // if (input.size() == 0)
    // {
    //     return 0;
    // }
    // sort(input.begin(), input.end());
    // std::cout << "\n";
    // int max_length = 1;
    // int count = 1;
    // for (int i = 1; i < input.size(); i++)
    // {
    //     if (i != 0 && input[i] == input[i - 1])
    //     {
    //         continue;
    //     }
    //     if (input[i] == input[i - 1] + 1)
    //     {
    //         count++;
    //     }
    //     else
    //     {
    //         count = 1;
    //     }
    //     max_length = std::max(max_length, count);
    // }

    if (input.size() == 0)
    {
        return 0;
    }
    std::unordered_map<int, int> map;
    map.reserve(1e5);
    map.max_load_factor(0.7);
    for (int i = 0; i < input.size(); i++)
    {
        map[input[i]]++;
    }
    int max_length = 1;
    for (int i = 0; i < input.size(); i++)
    {
        int length = lengthOfSequenceFromStart(input[i], map);
        max_length = std::max(max_length, length);
    }
    return max_length;
}

int lengthOfSequenceFromStart(int &start, std::unordered_map<int, int> &map)
{
    if (map.find(start - 1) != map.end())
    {
        return 0;
    }
    int length = 0;
    while (map.find(start) != map.end())
    {
        length++;
        start++;
    }
    return length;
}