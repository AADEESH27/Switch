#include <iostream>
#include <vector>

int searchInRotatedSortedArray(const std::vector<int> &input, const int &target);

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
    std::cout << searchInRotatedSortedArray(input, target) << "\n";
    return 0;
}

int searchInRotatedSortedArray(const std::vector<int> &input, const int &target)
{
    int left = 0;
    int right = input.size() - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (input[mid] == target)
        {
            return mid;
        }

        // left half is sorted
        else if (input[mid] >= input[left])
        {
            if (target >= input[left] && target < input[mid])
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }

        // right half is sorted
        else
        {
            if (target > input[mid] && target <= input[right])
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
    }
    return -1;
}
