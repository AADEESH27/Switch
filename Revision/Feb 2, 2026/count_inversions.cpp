#include <iostream>
#include <vector>

void mergeSort(std::vector<int> &input, int start, int end, int &count);
void merge(std::vector<int> &input, int start, int mid, int end, int &count);

int main()
{
    std::vector<int> input = {5, 3, 2, 4, 1};
    int count = 0;
    mergeSort(input, 0, input.size() - 1, count);
    std::cout << count << "\n";
    return 0;
}

void mergeSort(std::vector<int> &input, int start, int end, int &count)
{
    if (start >= end)
    {
        return;
    }
    int mid = start + (end - start) / 2;
    mergeSort(input, start, mid, count);
    mergeSort(input, mid + 1, end, count);
    merge(input, start, mid, end, count);
    return;
}

void merge(std::vector<int> &input, int start, int mid, int end, int &count)
{
    std::vector<int> temp;
    int i = start;
    int j = mid + 1;
    while (i <= mid && j <= end)
    {
        if (input[i] > input[j])
        {
            std::cout << input[i] << " " << input[j] << "\n";
            temp.push_back(input[j]);
            count += mid - i + 1;
            j++;
        }
        else
        {
            temp.push_back(input[i]);
            i++;
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
}
