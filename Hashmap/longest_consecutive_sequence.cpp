#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <climits>

int longestConsecutiveSequence(std::vector<int> &input);
int lengthOfSequenceFromStart(int &start, std::unordered_set<int> &set);

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
    std::unordered_set<int> set;
    set.reserve(1e5);
    set.max_load_factor(0.7);
    for (int i = 0; i < input.size(); i++)
    {
        set.insert(input[i]);
    }
    int max_length = INT_MIN;
    for (int i = 0; i < input.size(); i++)
    {
        int length = lengthOfSequenceFromStart(input[i], set);
        max_length = std::max(max_length, length);
    }
    return max_length;
}

int lengthOfSequenceFromStart(int &start, std::unordered_set<int> &set)
{
    if (set.find(start - 1) != set.end())
    {
        return 0;
    }
    int count = 1;
    while (set.find(start + 1) != set.end())
    {
        count++;
        start += 1;
    }
    return count;
}