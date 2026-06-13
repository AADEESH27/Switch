#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

int maxConsecutiveProduct(const std::vector<int> &input);

int main()
{
    int size;
    std::cin >> size;
    std::vector<int> input(size);
    for (int i = 0; i < size; i++)
    {
        std::cin >> input[i];
    }
    std::cout << maxConsecutiveProduct(input) << "\n";
    return 0;
}

int maxConsecutiveProduct(const std::vector<int> &input)
{
    if (input.size() == 1)
    {
        return input[0];
    }
    int max_prod = INT_MIN;
    int curr_pos = input[0];
    int curr_neg = input[0];
    for (int i = 1; i < input.size(); i++)
    {
        int option_1 = input[i];
        int option_2 = curr_pos * input[i];
        int option_3 = curr_neg * input[i];
        curr_pos = std::max(option_1, std::max(option_2, option_3));
        curr_neg = std::min(option_1, std::min(option_2, option_3));
        max_prod = std::max(max_prod, curr_pos);
    }
    return max_prod;
}
