#include <iostream>
#include <climits>
#include <vector>
#include <utility>

int main()
{
    int size;
    std::cin >> size;
    std::vector<int> input(size);
    for (int i = 0; i < size; i++)
    {
        int num;
        std::cin >> num;
        input[i] = num;
    }
    int max_cons_ones = INT_MIN;
    int curr_ones = 0;
    for (int i = 0; i < input.size(); i++)
    {
        if (input[i] == 1)
        {
            curr_ones++;
        }
        else
        {
            max_cons_ones = std::max(max_cons_ones, curr_ones);
            curr_ones = 0;
        }
    }
    if (curr_ones > max_cons_ones)
    {
        max_cons_ones = curr_ones;
        curr_ones = 0;
    }
    std::cout << "Max consecutinve ones: " << max_cons_ones << "\n";
    return 0;
}