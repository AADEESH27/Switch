#include <iostream>
#include <vector>

long long reversePairs(std::vector<int> &input);
void mergeSort(std::vector<int> &input, int start, int end, long long &count);
void merge(std::vector<int> &input, int start, int mid, int end, long long &count);

int main()
{
    int size;
    std::cin >> size;
    std::vector<int> input(size);
    for (int i = 0; i < size; i++)
    {
        std::cin >> input[i];
    }
    long long result = reversePairs(input);
    for (int i = 0; i < input.size(); i++)
    {
        std::cout << input[i] << " ";
    }
    std::cout << "\n";
    std::cout << result << "\n";
    return 0;
}

long long reversePairs(std::vector<int> &input)
{
    long long count = 0;
    mergeSort(input, 0, input.size() - 1, count);
    return count;
}

void mergeSort(std::vector<int> &input, int start, int end, long long &count)
{
    if (start >= end)
    {
        return;
    }
    int mid = start + (end - start) / 2;
    mergeSort(input, start, mid, count);
    mergeSort(input, mid + 1, end, count);
    merge(input, start, mid, end, count);
}

void merge(std::vector<int> &input, int start, int mid, int end, long long &count)
{
    std::vector<int> temp;
    int i = start;
    int j = mid + 1;
    while (i <= mid && j <= end)
    {
        // i is always less than j
        if (input[i] > (long long)2 * input[j])
        {
            count += ((mid - i) + 1);
            j++;
        }
        else
        {
            i++;
        }
    }
    i = start;
    j = mid + 1;
    while (i <= mid && j <= end)
    {
        if (input[i] <= input[j])
        {
            temp.push_back(input[i]);
            i++;
        }
        else
        {
            temp.push_back(input[j]);
            j++;
        }
    }
    while (i <= mid)
    {
        temp.push_back(input[i]);
        i++;
    }
    while (j <= end)
    {
        temp.push_back(input[j]);
        j++;
    }
    for (int i = start; i <= end; i++)
    {
        input[i] = temp[i - start];
    }
    return;
}