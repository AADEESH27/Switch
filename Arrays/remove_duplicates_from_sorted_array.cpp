#include <iostream>
#include <algorithm>
#include <vector>

int removeDuplicates(std::vector<int> &input);

int main()
{
    int size;
    std::cin >> size;
    std::vector<int> input(size);
    for (int i = 0; i < input.size(); i++)
    {
        std::cin >> input[i];
    }
    std::cout << removeDuplicates(input) << "\n";
    for (int i = 0; i < input.size(); i++)
    {
        std::cout << input[i] << " ";
    }
    std::cout << "\n";
    return 0;
}

int removeDuplicates(std::vector<int> &input)
{
    int back = 0;
    int front = 0;
    while (front < input.size())
    {
        if (input[back] == input[front])
        {
            front++;
        }
        else
        {
            if (back < input.size() - 1)
            {
                std::swap(input[back + 1], input[front]);
                back++;
                front++;
            }
        }
    }
    return ++back;
}