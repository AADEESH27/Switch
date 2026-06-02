#include <iostream>
#include <climits>
#include <vector>

int main()
{
    int size;
    std::cin >> size;
    std::vector<int> input(size);
    for (int i = 0; i < size; i++)
    {
        int num;
        std::cin >> num;
        input[i] = num;
    }
    int max_ele = INT_MIN;
    int second_max_ele = INT_MIN;
    for (int i = 0; i < input.size(); i++)
    {
        if (input[i] > max_ele)
        {
            second_max_ele = max_ele;
            max_ele = input[i];
        }
        else
        {
            if (input[i] != max_ele && input[i] > second_max_ele)
            {
                second_max_ele = input[i];
            }
        }
    }
    std::cout << "Max ele: " << max_ele << "\n";
    std::cout << "Second max ele: " << second_max_ele << "\n";
    return 0;
}