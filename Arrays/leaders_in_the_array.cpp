#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> leadersInTheArray(const std::vector<int> &input);

int main()
{
    int size;
    std::cin >> size;
    std::vector<int> input(size);
    for (int i = 0; i < size; i++)
    {
        std::cin >> input[i];
    }
    std::vector<int> result = leadersInTheArray(input);
    for (int i = 0; i < result.size(); i++)
    {
        std::cout << result[i] << " ";
    }
    std::cout << "\n";
    return 0;
}

std::vector<int> leadersInTheArray(const std::vector<int> &input)
{
    std::vector<int> leaders;
    int curr_leader = input[input.size() - 1];
    leaders.push_back(curr_leader);
    for (int i = input.size() - 2; i >= 0; i--)
    {
        if (input[i] > curr_leader)
        {
            curr_leader = input[i];
            leaders.push_back(curr_leader);
        }
    }
    std::reverse(leaders.begin(), leaders.end());
    return leaders;
}