#include <iostream>
#include <vector>
#include <algorithm>

int placeAggressiveCows(std::vector<int> &input, const int &cows);

bool checkIfDistanceIsSufficient(const std::vector<int> &input, const int &cows, const int &distance);

int main()
{
    int size;
    std::cin >> size;
    std::vector<int> input(size);
    for (int i = 0; i < input.size(); i++)
    {
        std::cin >> input[i];
    }
    int cows;
    std::cin >> cows;
    std::cout << placeAggressiveCows(input, cows) << "\n";
    return 0;
}

// maximize the minimum distance
// last true
// t t t t t f f f f f
int placeAggressiveCows(std::vector<int> &input, const int &cows)
{
    if (cows > input.size())
    {
        return -1;
    }
    std::sort(input.begin(), input.end());
    int left = 1; // if duplicate stall positions are there then the left = 0
    int right = input.back() - input.front();
    int ans = -1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        bool isDistanceSufficient = checkIfDistanceIsSufficient(input, cows, mid);
        if (isDistanceSufficient)
        {
            ans = mid;
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return ans;
}

bool checkIfDistanceIsSufficient(const std::vector<int> &input, const int &cows, const int &distance)
{
    int last_used_stall = input[0];
    int cows_placed = 1;
    for (int i = 1; i < input.size(); i++)
    {
        if (input[i] - last_used_stall >= distance)
        {
            cows_placed++;
            last_used_stall = input[i];
        }
        if (cows_placed >= cows)
        {
            return true;
        }
    }
    if (cows_placed < cows)
    {
        return false;
    }
    return true;
}