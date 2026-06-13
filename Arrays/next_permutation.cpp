#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

void nextPermutation(std::vector<int> &input);

int main()
{
    int size;
    std::cin >> size;
    std::vector<int> input(size);
    for (int i = 0; i < size; i++)
    {
        std::cin >> input[i];
    }
    nextPermutation(input);
    for (int i = 0; i < size; i++)
    {
        std::cout << input[i] << " ";
    }
    std::cout << "\n";
    return 0;
}

void nextPermutation(std::vector<int> &input)
{
    int possible_index = input.size();
    for (int i = input.size() - 2; i >= 0; i--)
    {
        if (input[i] < input[i + 1])
        {
            possible_index = i;
            break;
        }
    }
    if (possible_index == input.size())
    {
        std::reverse(input.begin(), input.end());
        return;
    }
    // int upper_bound = INT_MAX;
    // int upper_bound_index = -1;
    // for (int i = possible_index + 1; i < input.size(); i++)
    // {
    //     if (input[i] > input[possible_index])
    //     {
    //         // <= handles duplicates correctly refer the test case [35,45,87,49,72,63,60,74,90,42,47,50,69,12,45,10,30,61,6,55,9,96,89,43,5,83,66,78,63,59,58,12,41,97,25,100,12,57,30,79,30,1,39,98,43,41,45,97,15,36,18,5,30,81,80,49,77,84,5,36,78,68,7,41,35,11,21,49,87,85,36,55,4,66,78,4,7,7] here possible_index = 75 = 4 and upper_bound_index = 76 = first 7 but when you swap it becomes [35, ...., 7, 4, 7] then when you reverse [35, ...., 7, 7, 4] which is wrong so find the smallest element greater than possible_index with greatest index;
    //         if (input[i] <= upper_bound)
    //         {
    //             upper_bound = input[i];
    //             upper_bound_index = i;
    //         }
    //     }
    // }
    int upper_bound_index = input.size();
    for (int i = input.size() - 1; i > possible_index; i--)
    {
        if (input[i] > input[possible_index])
        {
            upper_bound_index = i;
            break;
        }
    }
    std::swap(input[possible_index], input[upper_bound_index]);
    std::reverse(input.begin() + possible_index + 1, input.end());
    return;
}