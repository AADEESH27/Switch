#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

int maxConsecutiveSum(const std::vector<int> &input);

int main()
{
    int size;
    std::cin >> size;
    std::vector<int> input(size);
    for (int i = 0; i < size; i++)
    {
        std::cin >> input[i];
    }
    std::cout << maxConsecutiveSum(input) << "\n";
    return 0;
}

int maxConsecutiveSum(const std::vector<int> &input)
{
    int max_sum = INT_MIN;
    int curr_sum = 0;
    for (int i = 0; i < input.size(); i++)
    {
        int option_1 = input[i];
        int option_2 = input[i] + curr_sum;
        curr_sum = std::max(option_1, option_2);
        max_sum = std::max(max_sum, curr_sum);
    }
    return max_sum;
}