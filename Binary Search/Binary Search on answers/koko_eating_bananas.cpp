#include <iostream>
#include <vector>
#include <climits>
#include <cmath>

int kokoBananaPerHourSpeed(const std::vector<int> &input, const int &limit);

int maxElement(const std::vector<int> &input);

bool checkIfSpeedIsSufficient(const std::vector<int> &input, const int &limit, const int &speed);

int main()
{
    int size;
    std::cin >> size;
    std::vector<int> input(size);
    for (int i = 0; i < size; i++)
    {
        std::cin >> input[i];
    }
    int limit;
    std::cin >> limit;
    std::cout << kokoBananaPerHourSpeed(input, limit) << "\n";
    return 0;
}

int kokoBananaPerHourSpeed(const std::vector<int> &input, const int &limit)
{
    int low = 1;
    int high = maxElement(input);
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        bool isSpeedSufficient = checkIfSpeedIsSufficient(input, limit, mid);
        if (isSpeedSufficient)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return low;
}

int maxElement(const std::vector<int> &input)
{
    int max_ele = INT_MIN;
    for (int i = 0; i < input.size(); i++)
    {
        max_ele = std::max(max_ele, input[i]);
    }
    return max_ele;
}

bool checkIfSpeedIsSufficient(const std::vector<int> &input, const int &limit, const int &speed)
{
    long long total_time_taken = 0;
    for (int i = 0; i < input.size(); i++)
    {
        total_time_taken += (input[i] + (speed - 1)) / speed;
        if (total_time_taken > limit)
        {
            return false;
        }
    }
    if (total_time_taken <= limit)
    {
        return true;
    }
    return false;
}