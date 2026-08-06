#include <iostream>
#include <vector>
#include <climits>

int minDaysToMakeBouquets(const std::vector<int> &input, const int &bouquets_required, const int &adjacent_roses);

int minElement(const std::vector<int> &input);

int maxElement(const std::vector<int> &input);

int checkIfDaysAreSufficent(const std::vector<int> &input, const int &bouquets_required, const int &adjacent_roses, int days);

int main()
{
    int size;
    std::cin >> size;
    std::vector<int> input(size);
    for (int i = 0; i < size; i++)
    {
        std::cin >> input[i];
    }
    int bouquets_required;
    std::cin >> bouquets_required;
    int adjacent_roses;
    std::cin >> adjacent_roses;
    std::cout << minDaysToMakeBouquets(input, bouquets_required, adjacent_roses);
    return 0;
}

int minDaysToMakeBouquets(const std::vector<int> &input, const int &bouquets_required, const int &adjacent_roses)
{
    if (bouquets_required * adjacent_roses > input.size())
    {
        std::cout << "here\n";
        return -1;
    }
    int ans = -1;
    int left = minElement(input);
    int right = maxElement(input);
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        bool areDaysSufficient = checkIfDaysAreSufficent(input, bouquets_required, adjacent_roses, mid);
        if (areDaysSufficient)
        {
            ans = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return ans;
}

int minElement(const std::vector<int> &input)
{
    int min_ele = INT_MAX;
    for (int i = 0; i < input.size(); i++)
    {
        if (input[i] < min_ele)
        {
            min_ele = input[i];
        }
    }
    return min_ele;
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

int checkIfDaysAreSufficent(const std::vector<int> &input, const int &bouquets_required, const int &adjacent_roses, int days)
{
    int max_adj_k_roses = 0;
    long long count = 0;
    for (int i = 0; i < input.size(); i++)
    {
        if (days >= input[i])
        {
            count++;
        }
        else
        {
            count = 0;
        }
        if (count == adjacent_roses)
        {
            max_adj_k_roses++;
            count = 0;
        }
        if (max_adj_k_roses >= bouquets_required)
        {
            return true;
        }
    }
    return false;
}