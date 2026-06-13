#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>

// better solution
//  why it works: set makes sure that the resultatnt triplet vectors are distinct and sorting the tripletes before saving makes sure the set comparison is accurate eg: If not sorted {1, 0, -1} and {-1, 1, 0} will be treated as different triplets

// optimal solution
// why it works: when sorted you can fix one element and to find other two you can use converging two pointer.
std::vector<std::vector<int>> threeSum(std::vector<int> &input, const int &target);

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
    std::vector<std::vector<int>> result = threeSum(input, target);
    for (int i = 0; i < result.size(); i++)
    {
        std::cout << result[i][0] << " " << result[i][1] << " " << result[i][2] << "\n";
    }
    return 0;
}

std::vector<std::vector<int>> threeSum(std::vector<int> &input, const int &target)
{
    std::vector<std::vector<int>> result;
    // std::set<std::vector<int>> triplet_set;
    // for (int i = 0; i < input.size(); i++)
    // {
    //     std::unordered_map<int, int> lookup_table;
    //     for (int j = i + 1; j < input.size(); j++)
    //     {
    //         int third_number = 0 - (input[i] + input[j]);
    //         std::unordered_map<int, int>::iterator it = lookup_table.find(third_number);
    //         if (it != lookup_table.end())
    //         {
    //             std::vector<int> temp = {input[i], input[j], third_number};
    //             sort(temp.begin(), temp.end()); // TC considered null as only three elements to sort
    //             triplet_set.insert(temp);
    //         }
    //         else
    //         {
    //             lookup_table[input[j]]++;
    //         }
    //     }
    // }
    // for (std::set<std::vector<int>>::iterator it = triplet_set.begin(); it != triplet_set.end(); it++)
    // {
    //     result.push_back(*it);
    // }
    // return result;

    sort(input.begin(), input.end());
    for (int i = 0; i < input.size() - 2; i++)
    {
        if (i != 0 && input[i] == input[i - 1])
        {
            continue;
        }
        int j = i + 1;
        int k = input.size() - 1;
        while (j < k)
        {
            int three_sum = input[i] + input[j] + input[k];
            if (three_sum == target)
            {
                result.push_back({input[i], input[j], input[k]});
                j++;
                k--;
                while (j < input.size() && input[j] == input[j - 1])
                    j++;
                while (k >= 0 && input[k] == input[k + 1])
                    k--;
            }
            else if (three_sum < target)
            {
                j++;
            }
            else
            {
                k--;
            }
        }
    }
    return result;
}