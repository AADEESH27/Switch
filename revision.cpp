#include <iostream>
#include <vector>
#include <algorithm>

void bubbleSort(std::vector<int> &input);
void selectionSort(std::vector<int> &input);
void insertionSort(std::vector<int> &input);

int main()
{
    int size;
    std::cin >> size;
    std::vector<int> input(size);
    for (int i = 0; i < size; i++)
    {
        std::cin >> input[i];
    }
    insertionSort(input);
    for (int i = 0; i < size; i++)
    {
        std::cout << input[i];
    }
    return 0;
}

void bubbleSort(std::vector<int> &input)
{
    for (int i = 0; i < input.size(); i++)
    {
        bool did_swap = false;
        for (int j = 1; j < input.size() - i; j++)
        {
            if (input[j] < input[j - 1])
            {
                std::swap(input[j], input[j - 1]);
                did_swap = true;
            }
        }
        if (!did_swap)
        {
            return;
        }
    }
    return;
}

void selectionSort(std::vector<int> &input)
{
    for (int i = 0; i < input.size(); i++)
    {
        int min_idx = i;
        for (int j = i + 1; j < input.size(); j++)
        {
            if (input[j] < input[min_idx])
            {
                min_idx = j;
            }
        }
        if (min_idx != i)
        {
            std::swap(input[i], input[min_idx]);
        }
    }
    return;
}

void insertionSort(std::vector<int> &input)
{
    for (int i = 0; i < input.size(); i++)
    {
        for (int j = i; j > 0; j--)
        {
            if (input[j] < input[j - 1])
            {
                std::swap(input[j], input[j - 1]);
            }
            else
            {
                break;
            }
        }
    }
    return;
}