#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

double medeanOfTwoSortedArrays(std::vector<int> &input_1, std::vector<int> &input_2);

int main()
{
    int size_1, size_2;
    std::cin >> size_1 >> size_2;
    std::vector<int> input_1(size_1);
    std::vector<int> input_2(size_2);
    for (int i = 0; i < size_1; i++)
    {
        std::cin >> input_1[i];
    }
    for (int i = 0; i < size_2; i++)
    {
        std::cin >> input_2[i];
    }
    std::cout << medeanOfTwoSortedArrays(input_1, input_2);
    return 0;
}

double medeanOfTwoSortedArrays(std::vector<int> &input_1, std::vector<int> &input_2)
{
    if (input_1.size() > input_2.size())
    {
        std::swap(input_1, input_2);
    }
    int n_1 = input_1.size();
    int n_2 = input_2.size();
    int final_length = n_1 + n_2;
    int left_side_length = (final_length + 1) / 2;
    int low = 0;
    int high = n_1;
    while (low <= high)
    {
        int cut_1 = low + (high - low) / 2;
        int cut_2 = left_side_length - cut_1;
        int l_1, l_2, r_1, r_2;

        l_1 = cut_1 == 0 ? INT_MIN : input_1[cut_1 - 1];
        l_2 = cut_2 == 0 ? INT_MIN : input_2[cut_2 - 1];
        r_1 = cut_1 == n_1 ? INT_MAX : input_1[cut_1];
        r_2 = cut_2 == n_2 ? INT_MAX : input_2[cut_2];
        if (l_1 <= r_2 && l_2 <= r_1)
        {
            if (final_length % 2 == 0)
            {
                return (double)((std::max(l_1, l_2) + std::min(r_1, r_2)) / 2.0);
            }
            else
            {
                return std::max(l_1, l_2);
            }
        }
        else if (l_1 > r_2)
        {
            // we have taken more elements from input_1
            high = cut_1 - 1;
        }
        else
        {
            low = cut_1 + 1;
        }
    }
    return 0.0;
}