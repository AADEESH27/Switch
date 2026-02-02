#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <algorithm>

auto findTriplets(int *input, int size, int target) -> void;

int main()
{
    int input[7] = {2, -2, 0, -3, 3, 5, -8};
    findTriplets(input, (sizeof(input) / sizeof(int)), 0);
    return 0;
}

void findTriplets(int *input, int size, int target)
{
    std::set<std::vector<int>> store;
    std::vector<std::vector<int>> result;
    // for (int i = 0; i < size - 2; i++)
    // {
    //     std::unordered_set<int> lookup_table;
    //     for (int j = i +; j < size; j++)
    //     {
    //         int num_to_find = target - (input[i] + input[j]);
    //         if (lookup_table.find(num_to_find) != lookup_table.end())
    //         {
    //             std::vector<int> temp;
    //             temp.push_back(input[i]);
    //             temp.push_back(input[j]);
    //             temp.push_back(num_to_find);
    //             sort(temp.begin(), temp.end());
    //             store.insert(temp);
    //         }
    //         lookup_table.insert(input[j]);
    //     }
    // }
    // for (auto it = store.begin(); it != store.end(); it++)
    // {
    //     result.push_back(*it);
    // }
    std::sort(input, input + size);
    for (int i = 0; i < size - 2; i++)
    {
        if (i > 0 && input[i] == input[i - 1])
        {
            continue;
        }
        int j = i + 1;
        int k = size - 1;
        while (j < k)
        {
            int curr_sum = input[i] + input[j] + input[k];
            if (curr_sum == target)
            {
                result.push_back({input[i], input[j], input[k]});
                j++;
                while (j < k && input[j] == input[j - 1])
                {
                    j++;
                }
                k--;
                while (j < k && input[k] == input[k + 1])
                {
                    k--;
                }
            }
            else if (curr_sum < target)
            {
                j++;
                while (j < k && input[j] == input[j - 1])
                {
                    j++;
                }
            }
            else
            {
                k--;
                while (j < k && input[k] == input[k + 1])
                {
                    k--;
                }
            }
        }
    }
    for (int i = 0; i < result.size(); i++)
    {
        std::cout << result[i][0] << " " << result[i][1] << " " << result[i][2] << "\n";
    }
    return;
}

void fourSum(int *input, int size, int target)
{
    // Brute force - 4 nested loops
    // Better same as 3 sum, fix first three then use hashing
    // set<vector<int>> store;
    // for (int i = 0; i < size - 3; i++) {
    //     for (int j = i + 1; j < size - 2; j++) {
    //         int k = j + 1;
    //         unordered_set<int> lookup_table;
    //         while (k < size) {
    //             int value_to_find = target - (input[i] + input[j] +
    //             input[k]); if (lookup_table.find(value_to_find) !=
    //                 lookup_table.end()) {
    //                 vector<int> temp;
    //                 temp.push_back(input[i]);
    //                 temp.push_back(input[j]);
    //                 temp.push_back(input[k]);
    //                 temp.push_back(value_to_find);
    //                 sort(temp.begin(), temp.end());
    //                 store.insert(temp);
    //             }
    //             lookup_table.insert(input[k]);
    //             k++;
    //         }
    //     }
    // }
    // vector<vector<int>> result;
    // for (auto it = store.begin(); it != store.end(); it++) {
    //     result.push_back(*it);
    // }
    // return result;
    std::vector<std::vector<int>> result;
    if (size < 4)
        return;
    std::sort(input, input + size);
    for (int i = 0; i < size - 3; i++)
    {
        if (i > 0 && input[i] == input[i - 1])
            continue;
        for (int j = i + 1; j < size - 2; j++)
        {
            if (j > i + 1 && input[j] == input[j - 1])
                continue;
            int k = j + 1;
            int l = size - 1;
            while (k < l)
            {
                int sum = input[i] + input[j] + input[k] + input[l];
                if (sum == target)
                {
                    result.push_back({input[i], input[j], input[k], input[l]});
                    k++;
                    while (k < l && input[k] == input[k - 1])
                        k++;
                    l--;
                    while (l > k && input[l] == input[l + 1])
                        l--;
                }
                else if (sum > target)
                {
                    l--;
                    while (l > k && input[l] == input[l + 1])
                        l--;
                }
                else
                {
                    k++;
                    while (k < l && input[k] == input[k - 1])
                        k++;
                }
            }
        }
    }
    // Print result
    return;
}