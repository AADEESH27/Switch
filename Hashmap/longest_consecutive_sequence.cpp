#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

int maxConsecutiveSequence(const std::vector<int> &input);

int main()
{
    std::vector<int> input = {100, -4, 200, 1, 2, -3};
    std::cout << maxConsecutiveSequence(input);
    return 0;
}

int maxConsecutiveSequence(const std::vector<int> &input)
{
    std::unordered_set<int> bag;
    int count = 1;
    int max_count = 1;
    for (int i = 0; i < input.size(); i++)
    {
        bag.insert(input[i]);
    }
    std::unordered_set<int>::iterator it;
    for (it = bag.begin(); it != bag.end(); it++)
    {
        int current_value = *it;
        if (bag.find(current_value - 1) == bag.end())
        {
            while (bag.find(current_value + 1) != bag.end())
            {
                count++;
                current_value += 1;
            }
            max_count = std::max(max_count, count);
            count = 1;
        }
    }
    return max_count;
}