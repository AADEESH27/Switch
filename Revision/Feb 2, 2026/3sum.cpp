#include <iostream>
#include <vector>
#include <algorithm>

std::vector<std::vector<int>> findTriplets(std::vector<int> &input, int k);

int main()
{
    std::vector<int> input = {-1, 0, 1, 2, -1, -4};
    std::vector<std::vector<int>> result = findTriplets(input, 0);
    for (int i = 0; i < result.size(); i++)
    {
        std::cout << result[i][0] << " " << result[i][1] << " " << result[i][2] << "\n";
    }
    return 0;
}

std::vector<std::vector<int>> findTriplets(std::vector<int> &input, int target)
{
    std::vector<std::vector<int>> result;
    std::sort(input.begin(), input.end());
    for (int i = 0; i < input.size() - 2; i++)
    {
        if (i > 0 && input[i] == input[i - 1])
        {
            continue;
        }
        int j = i + 1;
        int k = input.size() - 1;
        while (j < k)
        {
            int sum = input[i] + input[j] + input[k];
            if (sum == target)
            {
                result.push_back({input[i], input[j], input[k]});
                int val_j = input[j];
                while (j < k && input[j] == val_j)
                {
                    j++;
                }
                int val_k = input[k];
                while (k > j && input[k] == val_k)
                {
                    k--;
                }
            }
            else if (sum < target)
            {
                int val_j = input[j];
                while (j < input.size() && input[j] == val_j)
                {
                    j++;
                }
            }
            else
            {
                int val_k = input[k];
                while (k > i && input[k] == val_k)
                {
                    k--;
                }
            }
        }
    }
    return result;
}