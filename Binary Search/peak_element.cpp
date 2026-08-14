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
    if (input[0] > input[1])
        return 0;
    if (input[input.size() - 1] > input[input.size() - 2])
        return input.size() - 1;
    int low = 1;
    int high = input.size() - 2;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (input[mid - 1] < input[mid] && input[mid] > input[mid + 1])
        {
            return mid;
        }
        else if (input[mid - 1] < input[mid])
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}