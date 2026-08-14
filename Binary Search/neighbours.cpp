#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> neighboursWithKDistance(const std::vector<int> &input, const int k);

int main()
{
    int size;
    std::cin >> size;
    std::vector<int> input(size);
    for (int i = 0; i < input.size(); i++)
    {
        std::cin >> input[i];
    }
    int k;
    std::cin >> k;
    std::vector<int> result = neighboursWithKDistance(input, k);
    for (int i = 0; i < result.size(); i++)
    {
        std::cout << result[i] << " ";
    }
    return 0;
}

std::vector<int> neighboursWithKDistance(const std::vector<int> &input, const int k)
{
    std::vector<int> result;
    std::vector<int> input_copy = input;
    std::sort(input_copy.begin(), input_copy.end());
    for (int i = 0; i < input.size(); i++)
    {
        auto left = std::lower_bound(input_copy.begin(), input_copy.end(), (input[i] - k));
        auto right = std::upper_bound(input_copy.begin(), input_copy.end(), (input[i] + k));
        int count = right - left;
        result.push_back(count);
    }
    return result;
}