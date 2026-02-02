#include <iostream>
#include <vector>
#include <utility>

auto moveZerosToEnd(std::vector<int> &input) -> std::vector<int>;
int main()
{
    std::vector<int> input = {0, 1, 0, 3, 12};
    input = moveZerosToEnd(input);
    for (int ele : input)
    {
        std::cout << ele << " ";
    }
    std::cout << "\n";
    return 0;
}

std::vector<int> moveZerosToEnd(std::vector<int> &input)
{
    int size = input.size();
    int i = 0;
    while (i < size && input[i] != 0)
    {
        i++;
    }
    int j = i + 1;
    while (i < size && j < size)
    {
        if (input[j] != 0)
        {
            std::swap(input[i], input[j]);
            i++;
            j++;
        }
        else
        {
            j++;
        }
    }
    return input;
}