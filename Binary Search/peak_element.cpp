#include <iostream>
#include <vector>

int findPeakElement(const std::vector<int> &input);

int main()
{
    int size;
    std::cin >> size;
    std::vector<int> input(size);
    for (int i = 0; i < size; i++)
    {
        std::cin >> input[i];
    }
    std::cout << findPeakElement(input) << "\n";
    return 0;
}

int findPeakElement(const std::vector<int> &input)
{
    if (input.size() == 1)
    {
        return 0;
    }
    int left = 0;
    int right = input.size() - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (mid < input.size() - 1 && input[mid] <= input[mid + 1])
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return left;
}