#include <iostream>
#include <vector>
#include <climits>

int smallestDivisor(const std::vector<int> &input, const int limit);

int maxElement(const std::vector<int> &input);

bool checkIfChosenDivisorSatisfiesTheCondition(const std::vector<int> &input, const int limit, const int chosen_divisor);

int main()
{
    int size;
    std::cin >> size;
    std::vector<int> input(size);
    for (int i = 0; i < input.size(); i++)
    {
        std::cin >> input[i];
    }
    int limit;
    std::cin >> limit;
    std::cout << smallestDivisor(input, limit) << "\n";
    return 0;
}

int smallestDivisor(const std::vector<int> &input, const int limit)
{
    int low = 1;
    int high = maxElement(input);
    int ans = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        bool does_mid_satisfies = checkIfChosenDivisorSatisfiesTheCondition(input, limit, mid);
        if (does_mid_satisfies)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}

int maxElement(const std::vector<int> &input)
{
    int max_ele = INT_MIN;
    for (int i = 0; i < input.size(); i++)
    {
        if (input[i] > max_ele)
        {
            max_ele = input[i];
        }
    }
    return max_ele;
}

bool checkIfChosenDivisorSatisfiesTheCondition(const std::vector<int> &input, const int limit, const int chosen_divisor)
{
    long long sum = 0;
    for (int i = 0; i < input.size(); i++)
    {
        sum += (input[i] + (chosen_divisor - 1)) / chosen_divisor;
        if (sum > limit)
        {
            false;
        }
    }
    if (sum <= limit)
    {
        return true;
    }
    return false;
}