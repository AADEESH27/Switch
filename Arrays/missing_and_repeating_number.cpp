#include <iostream>
#include <vector>
#include <cmath>

std::vector<int> findMissingAndRepeatingNumber(const std::vector<int> &input);

int main()
{
    int size;
    std::cin >> size;
    std::vector<int> input(size);
    for (int i = 0; i < size; i++)
    {
        std::cin >> input[i];
    }
    std::vector<int> result = findMissingAndRepeatingNumber(input);
    for (int i = 0; i < result.size(); i++)
    {
        std::cout << result[i] << " ";
    }
    std::cout << "\n";
    return 0;
}

std::vector<int> findMissingAndRepeatingNumber(const std::vector<int> &input)
{
    // int missing = -1;
    // int repeating = -1;
    // std::vector<int> freq_arr(input.size() + 1, 0);
    // for (int i = 0; i < input.size(); i++)
    // {
    //     freq_arr[input[i]]++;
    // }
    // for (int i = 1; i < freq_arr.size(); i++)
    // {
    //     if (freq_arr[i] == 0)
    //     {
    //         missing = i;
    //     }
    //     if (freq_arr[i] == 2)
    //     {
    //         repeating = i;
    //     }
    // }
    // return {repeating, missing};

    int n = input.size();
    int missing = -1;
    int repeating = -1;
    long long expected_sum = (1LL * n * (n + 1)) / 2;
    long long expected_square_sum = (1LL * n * (n + 1) * ((2LL * n) + 1)) / 6;
    long long actual_sum = 0;
    long long actual_square_sum = 0;
    for (int i = 0; i < n; i++)
    {
        actual_sum += input[i];
        actual_square_sum += std::pow(input[i], 2);
    }
    missing = ((expected_sum - actual_sum) + ((expected_square_sum - actual_square_sum) / (expected_sum - actual_sum))) / 2;
    repeating = missing - (expected_sum - actual_sum);
    return {repeating, missing};
}