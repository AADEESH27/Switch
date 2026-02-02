#include <iostream>
#include <vector>

int maxProductSubarray(std::vector<int> &input);

int main()
{
    std::vector<int> input = {2, 3, -2, 4};
    std::cout << maxProductSubarray(input);
    return 0;
}

int maxProductSubarray(std::vector<int> &input)
{
    int max_product = input[0];
    int max_pos_product = input[0];
    int max_neg_product = input[0];
    for (int i = 1; i < input.size(); i++)
    {
        int option_1 = input[i];
        int option_2 = max_pos_product * input[i];
        int option_3 = max_neg_product * input[i];
        max_pos_product = std::max(option_1, std::max(option_2, option_3));
        max_neg_product = std::min(option_1, std::min(option_2, option_3));
        max_product = std::max(max_pos_product, max_product);
    }
    return max_product;
}
