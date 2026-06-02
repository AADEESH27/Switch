#include <iostream>
#include <vector>
#include <climits>

std::vector<int> majorityElementII(const std::vector<int> &input);

int main()
{
    int size;
    std::cin >> size;
    std::vector<int> input(size);
    for (int i = 0; i < size; i++)
    {
        std::cin >> input[i];
    }
    std::vector<int> result = majorityElementII(input);
    std::cout << "Result" << "\n";
    for (int ele : result)
    {
        std::cout << ele << " ";
    }
    std::cout << "\n";
    return 0;
}

std::vector<int> majorityElementII(const std::vector<int> &input)
{
    int maj_ele_1 = INT_MIN;
    int maj_ele_2 = INT_MIN;
    int count_1 = 0;
    int count_2 = 0;
    for (int i = 0; i < input.size(); i++)
    {
        if (count_1 == 0 && input[i] != maj_ele_2)
        {
            maj_ele_1 = input[i];
            count_1++;
        }
        else if (count_2 == 0 && input[i] != maj_ele_1)
        {
            maj_ele_2 = input[i];
            count_2++;
        }
        else if (input[i] == maj_ele_1)
        {
            count_1++;
        }
        else if (input[i] == maj_ele_2)
        {
            count_2++;
        }
        else
        {
            count_1--;
            count_2--;
        }
    }
    std::cout << maj_ele_1 << " " << maj_ele_2 << "\n";
    count_1 = count_2 = 0;
    std::vector<int> result;
    for (int i = 0; i < input.size(); i++)
    {
        if (input[i] == maj_ele_1)
        {
            count_1++;
        }
    }
    if (count_1 > input.size() / 3)
    {
        result.push_back(maj_ele_1);
    }
    for (int i = 0; i < input.size(); i++)
    {
        if (input[i] == maj_ele_2)
        {
            count_2++;
        }
    }
    if (count_2 > input.size() / 3)
    {
        result.push_back(maj_ele_2);
    }
    return result;
}