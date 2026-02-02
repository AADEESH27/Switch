/*
Subarrays:
    1. Printing all subarrays
    2. Max sum of subarrays. // Kadane's does this in O(n)
    3. Max product of subarrays
*/

#include <iostream>
#include <climits>

auto printAllSubarrays(int *arr, int size) -> void;
auto maxSum(int *arr, int size) -> int;
auto maxProd(int *arr, int size) -> int;

int main()
{
    int arr[10] = {4, 5, 3, 7, -2, 8, -3, -4, 5, -6};
    int size = sizeof(arr) / sizeof(int);
    // printAllSubarrays(arr, 6);
    // std::cout << maxSum(arr, 6) << "\n";
    std::cout << maxProd(arr, size) << "\n";
    return 0;
}

void printAllSubarrays(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = i; j < size; j++)
        {
            for (int k = i; k <= j; k++)
            {
                std::cout << arr[k] << " ";
            }
            std::cout << "\n";
        }
        std::cout << "\n";
    }
    return;
}

int maxSum(int *arr, int size)
{
    int max_sum = INT_MIN;
    int start, end;
    for (int i = 0; i < size; i++)
    {
        int sum = 0;
        for (int j = i; j < size; j++)
        {
            sum += arr[j];
            std::cout << sum << "\n";
            if (sum > max_sum)
            {
                max_sum = sum;
                start = i;
                end = j;
            }
        }
    }
    for (int i = start; i <= end; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
    return max_sum;
}

int maxProd(int *arr, int size)
{
    int max_prod = INT_MIN;
    int start, end;
    for (int i = 0; i < size; i++)
    {
        int prod = 1;
        for (int j = i; j < size; j++)
        {
            prod *= arr[j];
            if (prod > max_prod)
            {
                max_prod = prod;
                start = i;
                end = j;
            }
        }
    }
    for (int i = start; i <= end; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
    return max_prod;
}