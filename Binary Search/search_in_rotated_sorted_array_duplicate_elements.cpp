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
        // with duplicates it could be possible that mid, left, right all have the same values because of which we are not able to find the sorted half
        if (input[left] == input[mid] && input[mid] == input[right])
        {
            left++;
            right--;
            continue; // skip this iteration
        }
        // left half is sorted
        else if (input[left] <= input[mid])
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
