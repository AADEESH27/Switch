#include <iostream>
#include <vector>

std::vector<int> unionOfTwoSortedArrays(const std::vector<int> &v1, const std::vector<int> &v2);

int main()
{
    int size1, size2;
    std::cin >> size1 >> size2;
    std::vector<int> v1(size1);
    std::vector<int> v2(size2);
    for (int i = 0; i < size1; i++)
    {
        std::cin >> v1[i];
    }
    for (int i = 0; i < size2; i++)
    {
        std::cin >> v2[i];
    }
    std::vector<int> result = unionOfTwoSortedArrays(v1, v2);
    for (int i = 0; i < result.size(); i++)
    {
        std::cout << result[i] << " ";
    }
    std::cout << "\n";
    return 0;
}

std::vector<int> unionOfTwoSortedArrays(const std::vector<int> &v1, const std::vector<int> &v2)
{
    std::vector<int> result;
    int ind1 = 0;
    int ind2 = 0;
    while (ind1 < v1.size() && ind2 < v2.size())
    {
        if (v1[ind1] <= v2[ind2])
        {
            if (result.size() == 0)
            {
                result.push_back(v1[ind1]);
                ind1++;
            }
            else if (result.size() >= 1 && result.back() != v1[ind1])
            {
                result.push_back(v1[ind1]);
                ind1++;
            }
            else
            {
                ind1++;
            }
        }
        else
        {
            if (result.size() == 0)
            {
                result.push_back(v2[ind2]);
                ind2++;
            }
            else if (result.size() >= 1 && result.back() != v2[ind2])
            {
                result.push_back(v2[ind2]);
                ind2++;
            }
            else
            {
                ind2++;
            }
        }
    }
    while (ind1 < v1.size())
    {
        if (result.size() == 0)
        {
            result.push_back(v1[ind1]);
            ind1++;
        }
        else if (result.size() >= 1 && result.back() != v1[ind1])
        {
            result.push_back(v1[ind1]);
            ind1++;
        }
        else
        {
            ind1++;
        }
    }
    while (ind2 < v2.size())
    {
        if (result.size() == 0)
        {
            result.push_back(v2[ind2]);
            ind2++;
        }
        else if (result.size() >= 1 && result.back() != v2[ind2])
        {
            result.push_back(v2[ind2]);
            ind2++;
        }
        else
        {
            ind2++;
        }
    }
    return result;
}