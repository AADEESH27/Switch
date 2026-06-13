#include <iostream>
#include <vector>
#include <algorithm>

void dutchNationalFlag(std::vector<int> &input);

int main()
{
    int size;
    std::cin >> size;
    std::vector<int> input(size);
    for (int i = 0; i < size; i++)
    {
        std::cin >> input[i];
    }
    dutchNationalFlag(input);
    for (int i = 0; i < input.size(); i++)
    {
        std::cout << input[i] << " ";
    }
    std::cout << "\n";
    return 0;
}

void dutchNationalFlag(std::vector<int> &input)
{
    int low = 0;
    int mid = 0;
    int high = input.size() - 1;
    while (mid <= high)
    {
        if (input[mid] == 1)
        {
            mid++;
        }
        else if (input[mid] == 0)
        {
            std::swap(input[low], input[mid]);
            low++;
            mid++;
        }
        else
        {
            std::swap(input[mid], input[high]);
            high--;
        }
    }
    return;
}
