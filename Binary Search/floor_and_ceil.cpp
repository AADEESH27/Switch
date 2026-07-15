#include <iostream>
#include <vector>

std::vector<int> floorAndCeil(const std::vector<int> &input, const int &target);

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
    std::vector<int> result = floorAndCeil(input, target);
    for (int i = 0; i < result.size(); i++)
    {
        std::cout << result[i] << " ";
    }
    std::cout << "\n";
    return 0;
}

std::vector<int> floorAndCeil(const std::vector<int> &input, const int &target)
{
    int left_pointer = 0;
    int right_pointer = input.size() - 1;
    while (left_pointer <= right_pointer)
    {
        int mid_pointer = left_pointer + (right_pointer - left_pointer) / 2;
        if (input[mid_pointer] == target)
        {
            return {input[mid_pointer], input[mid_pointer]};
        }
        else if (input[mid_pointer] > target)
        {
            right_pointer = mid_pointer - 1;
        }
        else
        {
            left_pointer = mid_pointer + 1;
        }
    }
    int floor = -1;
    int ceil = -1;
    if (left_pointer == 0)
    {
        ceil = input[left_pointer];
    }
    else if (left_pointer >= input.size())
    {
        floor = input[input.size() - 1];
    }
    else
    {
        floor = input[left_pointer - 1];
        ceil = input[left_pointer];
    }
    return {floor, ceil};
}