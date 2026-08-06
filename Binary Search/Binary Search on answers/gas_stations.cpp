#include <iostream>
#include <vector>
#include <climits>
#include <cmath>

long double minimiseMaxDistance(const std::vector<int> &input, const int k);
long double getMaxAdjacentDistance(const std::vector<int> &input);
bool checkIisMaxDistanceFeasible(const std::vector<int> &input, const int k, const long double max_adjacent_distance);

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
    std::cout << minimiseMaxDistance(input, k);
    return 0;
}

long double minimiseMaxDistance(const std::vector<int> &input, const int k)
{
    long double low = 0;
    long double high = getMaxAdjacentDistance(input);
    long double ans = -1;
    while (high - low > 1e-6)
    {
        long double mid = low + (high - low) / 2.0;
        bool is_max_distance_feasible = checkIisMaxDistanceFeasible(input, k, mid);
        if (is_max_distance_feasible)
        {
            ans = mid;
            high = mid;
        }
        else
        {
            low = mid;
        }
    }
    return ans;
}

long double getMaxAdjacentDistance(const std::vector<int> &input)
{
    long double max_adjacent_distance = INT_MIN;
    for (int i = 1; i < input.size(); i++)
    {
        if (input[i] - input[i - 1] > max_adjacent_distance)
        {
            max_adjacent_distance = input[i] - input[i - 1];
        }
    }
    return max_adjacent_distance;
}

bool checkIisMaxDistanceFeasible(const std::vector<int> &input, const int k, const long double max_adjacent_distance)
{
    // although simulation is good to get an understanding but will eventually lead to TLE
    // long double last_used_spot = input[0];
    // int count = 0;
    // for (int i = 1; i < input.size(); i++)
    // {
    //     while (last_used_spot + max_adjacent_distance < input[i])
    //     {
    //         count++;
    //         if (count > k)
    //         {
    //             return false;
    //         }
    //         last_used_spot = last_used_spot + max_adjacent_distance;
    //     }
    //     last_used_spot = input[i];
    // }
    // return false;

    int count = 0;
    for (int i = 1; i < input.size(); i++)
    {
        int stations_between_two_original_spots = std::ceil((input[i] - input[i - 1]) / max_adjacent_distance) - 1;
        count += stations_between_two_original_spots;
        if (count > k)
        {
            return false;
        }
    }
    return true;
}