#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int size;
    std::cin >> size;
    std::vector<int> input(size);
    for (int i = 0; i < size; i++)
    {
        std::cin >> input[i];
    }
    int zero = 0;
    while (input[zero] != 0)
        zero++;
    int non_zero = zero + 1;
    while (non_zero < input.size())
    {
        if (input[non_zero] != 0)
        {
            std::swap(input[zero], input[non_zero]);
            while (input[zero] != 0)
                zero++;
            non_zero++;
        }
        else
        {
            non_zero++;
        }
    }
    for (int i = 0; i < input.size(); i++)
    {
        std::cout << input[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}