#include <iostream>
#include <algorithm>

int main()
{
    int arr[5] = {0, 1, 4, 0, 5};
    int i = 0;
    while (i < 5 && arr[i] != 0)
        i++;
    int j = i + 1;
    while (i < 5 && j < 5)
    {
        if (arr[i] == 0 && arr[j] != 0)
        {
            std::swap(arr[i], arr[j]);
            i++;
        }
        j++;
    }
    for (int x : arr)
    {
        std::cout << x << " ";
    }
    std::cout << "\n";
    return 0;
}