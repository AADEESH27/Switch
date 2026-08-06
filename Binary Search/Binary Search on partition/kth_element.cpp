#include <iostream>
#include <vector>
#include <climits>

int findTheKthElement(std::vector<int> &input_1, std::vector<int> &input_2, const int &k);
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
    int k;
    std::cin >> k;
    std::cout << findTheKthElement(input_1, input_2, k) << "\n";
    return 0;
}

int findTheKthElement(std::vector<int> &input_1, std::vector<int> &input_2, const int &k)
{
    if (input_1.size() > input_2.size())
    {
        // swap() does it in O(1)
        std::swap(input_1, input_2);
    }
    int n_1 = input_1.size();
    int n_2 = input_2.size();
    int left_part = k;
    int low = std::max(0, k - n_2);
    int high = std::min(k, n_1);
    while (low <= high)
    {
        int cut_1 = low + (high - low) / 2;
        int cut_2 = left_part - cut_1;
        int l_1 = cut_1 == 0 ? INT_MIN : input_1[cut_1 - 1];
        int r_1 = cut_1 == n_1 ? INT_MAX : input_1[cut_1];
        int l_2 = cut_2 == 0 ? INT_MIN : input_2[cut_2 - 1];
        int r_2 = cut_2 == n_2 ? INT_MAX : input_2[cut_2];
        if (l_1 <= r_2 && l_2 <= r_1)
        {
            return std::max(l_1, l_2);
        }
        else if (l_1 > r_2)
        {
            // too many elements from input 1
            high = cut_1 - 1;
        }
        else
        {
            low = cut_1 + 1;
        }
    }
    return 0;
}