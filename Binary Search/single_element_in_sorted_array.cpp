#include <iostream>
#include <vector>

int singleElementInSortedArray(const std::vector<int> &input);

int main()
{
    int size;
    std::cin >> size;
    std::vector<int> input(size);
    for (int i = 0; i < size; i++)
    {
        std::cin >> input[i];
    }
    std::cout << singleElementInSortedArray(input) << "\n";
    return 0;
}

int singleElementInSortedArray(const std::vector<int> &input)
{
    // min size has to be 3
    if (input.size() == 1 || input.size() == 2)
    {
        return input[0];
    }
    int left = 0;
    int right = input.size() - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        // check which occurance is the number at mid is 1 or 2
        if (mid - 1 >= 0 && input[mid] == input[mid - 1])
        { // second occurance
            if (mid % 2 == 0)
            { // after single element
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        else if (mid + 1 < input.size() && input[mid] == input[mid + 1])
        { // first occurance
            if (mid % 2 == 0)
            { // before single element
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        else
        {
            return input[mid];
        }
    }
    return 0;
}