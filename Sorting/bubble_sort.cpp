#include <iostream>
#include <algorithm>

// Stable: Equal elements are not swapped
// Better for nearly sorted or very small input array as it gets it done in O(n)

void bubbleSort(int *arr, int size);
void swap(int *arr, int ind1, int ind2);

int main()
{
    int arr[5] = {5, 4, 3, 2, 1};
    bubbleSort(arr, 5);
    for (int num : arr)
    {
        std::cout << num << " ";
    }
    std::cout << "\n";
    return 0;
}

void bubbleSort(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 1; j < size - i; j++)
        {
            if (arr[j] < arr[j - 1])
            {
                swap(arr, j, j - 1);
            }
        }
    }
    return;
}

void swap(int *arr, int ind1, int ind2)
{
    int temp = arr[ind1];
    arr[ind1] = arr[ind2];
    arr[ind2] = temp;
    return;
}