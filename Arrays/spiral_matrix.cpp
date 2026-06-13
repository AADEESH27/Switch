#include <iostream>
#include <vector>

std::vector<int> printSpiral(const std::vector<std::vector<int>> &input, int m, int n);

int main()
{
    int m, n;
    std::cin >> m >> n;
    std::vector<std::vector<int>> input(m, std::vector<int>(n));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            std::cin >> input[i][j];
        }
    }
    std::vector<int> result = printSpiral(input, m, n);
    for (int i = 0; i < result.size(); i++)
    {
        std::cout << result[i] << " ";
    }
    std::cout << "\n";
    return 0;
}

std::vector<int> printSpiral(const std::vector<std::vector<int>> &input, int m, int n)
{
    std::vector<int> result;
    if (m == 1)
    {
        for (int i = 0; i < n; i++)
        {
            result.push_back(input[0][i]);
        }
        return result;
    }
    if (n == 1)
    {
        for (int i = 0; i < m; i++)
        {
            result.push_back(input[i][0]);
        }
        return result;
    }
    int total_elements = m * n;
    int i = 0;
    int j = 0;
    int k = n - 1;
    int l = m - 1;
    int count = 0;
    while (count <= total_elements)
    {
        for (int p = i; p <= k; p++)
        {
            result.push_back(input[j][p]);
            count++;
        }
        j++;
        if (count >= total_elements)
            break;
        for (int p = j; p <= l; p++)
        {
            result.push_back(input[p][k]);
            count++;
        }
        k--;
        if (count >= total_elements)
            break;
        for (int p = k; p >= i; p--)
        {
            result.push_back(input[l][p]);
            count++;
        }
        l--;
        if (count >= total_elements)
            break;
        for (int p = l; p >= j; p--)
        {
            result.push_back(input[p][i]);
            count++;
        }
        i++;
        if (count >= total_elements)
            break;
    }
    return result;
}