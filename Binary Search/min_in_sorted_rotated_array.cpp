#include <iostream>
#include <vector>

int minInSortedRotatedArray(const std::vector<int> &input);

int main()
{
    int size;
    std::cin >> size;
    std::vector<int> input(size);
    for (int i = 0; i < size; i++)
    {
        std::cin >> input[i];
    }
    std::cout << minInSortedRotatedArray(input) << "\n";
    return 0;
}

int minInSortedRotatedArray(const std::vector<int> &input)
{
    int left = 0;
    int right = input.size() - 1;
    while (left < right)
    {
        if (input[left] < input[right])
        {
            return input[left];
        }
        int mid = left + (right - left) / 2;
        // move towards unsorted half
        if (input[left] <= input[mid])
        {
            left = mid + 1;
        }
        else
        {
            right = mid;
        }
    }
    return input[left];
}