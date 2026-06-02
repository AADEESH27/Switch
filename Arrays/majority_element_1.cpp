#include <iostream>
#include <vector>

int majorityElement(const std::vector<int> &input);

int main()
{
    int size;
    std::cin >> size;
    std::vector<int> input(size);
    for (int i = 0; i < size; i++)
    {
        std::cin >> input[i];
    }
    std::cout << majorityElement(input);
    return 0;
}

int majorityElement(const std::vector<int> &input)
{
    int maj_ele = input[0];
    int count = 0;
    for (int i = 0; i < input.size(); i++)
    {
        if (input[i] == maj_ele)
            count++;
        else
            count--;
        if (count == 0)
        {
            maj_ele = input[i];
            count = 1;
        }
    }
    return maj_ele;
}