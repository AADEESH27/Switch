#include <iostream>
#include <vector>
#include <climits>

int cleaningWindows(const std::vector<int> &input, const int limit);
int maxEle(const std::vector<int> &input);
bool checkIfSpeedFeasible(const std::vector<int> &input, const int limit, const int speed);

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
    std::cout << cleaningWindows(input, limit) << "\n";
    return 0;
}

int cleaningWindows(const std::vector<int> &input, const int limit)
{
    int low = 1;
    int high = maxEle(input);
    int ans = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        bool is_speed_feasible = checkIfSpeedFeasible(input, limit, mid);
        if (!is_speed_feasible)
        {
            low = mid + 1;
        }
        else
        {
            ans = mid;
            high = mid - 1;
        }
    }
    return ans;
}

int maxEle(const std::vector<int> &input)
{
    int max_ele = INT_MIN;
    for (int i = 0; i < input.size(); i++)
    {
        max_ele = std::max(max_ele, input[i]);
    }
    return max_ele;
}

bool checkIfSpeedFeasible(const std::vector<int> &input, const int limit, const int speed)
{
    int time_taken = 0;
    for (int i = 0; i < input.size(); i++)
    {
        time_taken += (input[i] + (speed - 1)) / speed;
        if (time_taken > limit)
        {
            return false;
        }
    }
    return true;
}