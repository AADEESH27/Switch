#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
#include <algorithm>

std::vector<std::vector<long long>> fourSum(std::vector<int> &input, int target);
int main()
{
    int size;
    std::cin >> size;
    std::vector<int> input(size);
    for (int i = 0; i < size; i++)
    {
        std::cin >> input[i];
    }
    int target;
    std::cin >> target;
    std::vector<std::vector<long long>> result = fourSum(input, target);
    for (int i = 0; i < result.size(); i++)
    {
        std::cout << result[i][0] << " " << result[i][1] << " " << result[i][2] << " " << result[i][3] << "\n";
    }
    return 0;
}

std::vector<std::vector<long long>> fourSum(std::vector<int> &input, int target)
{
    // std::vector<std::vector<long long>> result;
    // std::set<std::vector<long long>> quadriplets;
    // for (int i = 0; i < input.size(); i++)
    // {
    //     for (int j = i + 1; j < input.size(); j++)
    //     {
    //         std::unordered_map<long long, int> lookup_table;
    //         for (int k = j + 1; k < input.size(); k++)
    //         {
    //             long long fourth_number = (long long)target - (input[i] + input[j] + input[k]); // int can overflow if all a[i], a[j] and a[k] are big numbers.
    //             auto it = lookup_table.find(fourth_number);
    //             if (it != lookup_table.end())
    //             {
    //                 std::vector<long long> temp = {input[i],
    //                                                input[j],
    //                                                input[k],
    //                                                it->first};
    //                 std::sort(temp.begin(), temp.end());
    //                 quadriplets.insert(temp);
    //             }
    //             else
    //             {
    //                 lookup_table[input[k]]++;
    //             }
    //         }
    //         lookup_table.clear();
    //     }
    // }
    // for (auto it = quadriplets.begin(); it != quadriplets.end(); it++)
    // {
    //     result.push_back(*it);
    // }
    std::vector<std::vector<long long>> result;
    sort(input.begin(), input.end());
    for (int i = 0; i < input.size(); i++)
    {
        if (i != 0 && input[i] == input[i - 1])
        {
            continue;
            for (int j = i + 1; j < input.size(); j++)
            {
                if (j != i + 1 && input[j] == input[j - 1])
                {
                    continue;
                }
            }
            for (int j = i + 1; j < input.size(); j++)
            {
                if (j != i + 1 && input[j] == input[j - 1])
                {
                    continue;
                }
                int k = j + 1;
                int l = input.size() - 1;
                while (k < l)
                {
                    int sum = input[i] + input[j] + input[k] + input[l];
                    if (sum == target)
                    {
                        result.push_back({input[i], input[j], input[k], input[l]});
                        k++;
                        l--;
                        while (k < input.size() && input[k] == input[k - 1])
                            k++;
                        while (l >= 0 && input[l] == input[l + 1])
                            l--;
                    }
                    else if (sum < target)
                    {
                        k++;
                    }
                    else
                    {
                        l--;
                    }
                }
            }
        }
        return result;
    }