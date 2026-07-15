#include <iostream>
#include <vector>

int upperBound(const std::vector<int> &input, const int &target);
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
    std::cout << upperBound(input, target);
    return 0;
}

int upperBound(const std::vector<int> &input, const int &target)
{
    int left_pointer = 0;
    int right_pointer = input.size() - 1;
    while (left_pointer <= right_pointer)
    {
        int mid = left_pointer + (right_pointer - left_pointer) / 2;
        if (input[mid] <= target)
        {
            left_pointer = mid + 1;
        }
        else
        {
            right_pointer = mid - 1;
        }
    }
    return left_pointer == input.size() ? -1 : left_pointer;
}