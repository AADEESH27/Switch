#include <iostream>
#include <vector>

int lowerBound(const std::vector<int> &input, const int &target);
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
    std::cout << lowerBound(input, target);
    return 0;
}

int lowerBound(const std::vector<int> &input, const int &target)
{
    int left_pointer = 0;
    int right_pointer = input.size() - 1;
    while (left_pointer <= right_pointer)
    {
        int mid_pointer = left_pointer + (right_pointer - left_pointer) / 2;
        if (input[mid_pointer] >= target)
        {
            right_pointer = mid_pointer - 1;
        }
        else
        {
            left_pointer = mid_pointer + 1;
        }
    }
    return left_pointer == input.size() ? -1 : left_pointer;
}