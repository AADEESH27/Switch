#include <iostream>
#include <vector>

std::vector<int> intersectionOfTwoArrays(const std::vector<int> &v1, const std::vector<int> &v2);

int main()
{
    int size1, size2;
    std::cin >> size1 >> size2;
    std::vector<int> v1(size1), v2(size2);
    for (int i = 0; i < size1; i++)
    {
        std::cin >> v1[i];
    }
    for (int i = 0; i < size2; i++)
    {
        std::cin >> v2[i];
    }
    std::vector<int> result = intersectionOfTwoArrays(v1, v2);
    for (int i = 0; i < result.size(); i++)
    {
        std::cout << result[i] << " ";
    }
    std::cout << "\n";
    return 0;
}

std::vector<int> intersectionOfTwoArrays(const std::vector<int> &v1, const std::vector<int> &v2)
{
    std::vector<int> result;
    int i = 0;
    int j = 0;
    while (i < v1.size() && j < v2.size())
    {
        if (v1[i] == v2[j])
        {
            result.push_back(v1[i]);
            i++;
            j++;
        }
        else if (v1[i] < v2[j])
        {
            i++;
        }
        else
        {
            j++;
        }
    }
    return result;
    std::vector<int> result;
    int i = 0;
    int j = 0;
    while (i < v1.size() && j < v2.size())
    {
        if (v1[i] == v2[j])
        {
            result.push_back(v1[i]);
            i++;
            j++;
        }
        else if (v1[i] < v2[j])
        {
            i++;
        }
        else
        {
            j++;
        }
    }
    return result;
}