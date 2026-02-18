#include <iostream>
#include <climits>

int main()
{
    int arr[5] = {4, 5, 2, 6, 1};
    int max_ele = INT_MIN;
    int second_max_ele = INT_MIN;
    for (int x : arr)
    {
        if (x > max_ele)
        {
            second_max_ele = max_ele;
            max_ele = x;
        }
        else
        {
            if (x > second_max_ele && x < max_ele)
            {
                second_max_ele = x;
            }
        }
    }
    std::cout << (second_max_ele == INT_MIN ? -1 : second_max_ele);
    return 0;
}