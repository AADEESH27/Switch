#include <iostream>
#include <vector>

std::vector<int> firstAndLastOccurance(const std::vector<int> &input, const int &target);

// firstOccurance = lower bound
/*
two cases
1-> if lower_bound = size that means target is not present and greater than the greatest element in the array so return -1;
2-> if lower_bound = 0; check if [lower_bound] == target good return lower_bound else return -1;
*/
int firstOccurance(const std::vector<int> &input, const int &target);

// lastOccurance = upper bound - 1
int lastOccurance(const std::vector<int> &input, const int &target);

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
    std::vector<int> result = firstAndLastOccurance(input, target);
    for (int i = 0; i < result.size(); i++)
    {
        std::cout << result[i] << " ";
    }
    std::cout << "\n";
    return 0;
}

std::vector<int> firstAndLastOccurance(const std::vector<int> &input, const int &target)
{
    if (input.size() == 0)
    {
        return {-1, -1};
    }
    int first_occurance = firstOccurance(input, target);
    if (first_occurance == -1)
    {
        return {-1, -1};
    }
    int last_occurance = lastOccurance(input, target);
    return {first_occurance, last_occurance};
}

int firstOccurance(const std::vector<int> &input, const int &target)
{
    int left = 0;
    int right = input.size() - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (input[mid] >= target)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    if (input[left] != target || left == input.size())
    {
        return -1;
    }
    return left;
}

int lastOccurance(const std::vector<int> &input, const int &target)
{
    int left = 0;
    int right = input.size() - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (input[mid] <= target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return left - 1;
}