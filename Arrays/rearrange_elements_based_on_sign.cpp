#include <iostream>
#include <vector>

std::vector<int> rearrageBySign(const std::vector<int> &input);

int main()
{
    int n;
    std::cin >> n;
    while (n > 0)
    {
        int size;
        std::cin >> size;
        std::vector<int> input(size);
        for (int i = 0; i < size; i++)
        {
            std::cin >> input[i];
        }
        std::vector<int> result = rearrageBySign(input);
        for (int i = 0; i < result.size(); i++)
        {
            std::cout << result[i] << " ";
        }
        std::cout << "\n";
        n--;
    }
    return 0;
}

std::vector<int> rearrageBySign(const std::vector<int> &input)
{
    int size = input.size();
    std::vector<int> result(size);
    int i = 0;
    int pos = 0;
    int neg = 1;
    while (i < size && pos < size && neg < size)
    {
        if (input[i] > 0)
        {
            result[pos] = input[i];
            pos += 2;
        }
        else
        {
            result[neg] = input[i];
            neg += 2;
        }
        i++;
    }
    while (i < size && pos < size)
    {
        result[pos] = input[i];
        pos += 2;
        i++;
    }
    while (i < size && neg < size)
    {
        result[neg] = input[i];
        neg += 2;
        i++;
    }
    return result;
}