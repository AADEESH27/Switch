#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

int medianOfRowWiseSortedMatrix(const std::vector<std::vector<int>> &matrix);
int minInRowWiseSortedMax(const std::vector<std::vector<int>> &matrix);
int maxInRowWiseSortedMax(const std::vector<std::vector<int>> &matrix);
int checkHowManyElementsLessThanEqualToMid(const std::vector<std::vector<int>> &matrix, const int &mid);

int main()
{
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> matrix(n, std::vector<int>(m));
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            std::cin >> matrix[i][j];
        }
    }
    return 0;
}

int medianOfRowWiseSortedMatrix(const std::vector<std::vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    int low = minInRowWiseSortedMax(matrix);
    int high = maxInRowWiseSortedMax(matrix);
    int median = (n * m + 1) / 2;
    int ans = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        // check how many elements <= mid;
        int count = checkHowManyElementsLessThanEqualToMid(matrix, mid); // nlogm
        if (count < median)
        {
            low = mid + 1;
        }
        else
        {
            ans = mid;
            high = mid - 1;
        }
    } // total nlogm*log(max - min + 1)
    return ans;
}

int minInRowWiseSortedMax(const std::vector<std::vector<int>> &matrix)
{
    // can get in linear time by comparing i[0]
    int min_ele = INT_MAX;
    for (int i = 0; i < matrix.size(); i++)
    {
        min_ele = std::min(min_ele, matrix[i][0]);
    }
    return min_ele;
}

int maxInRowWiseSortedMax(const std::vector<std::vector<int>> &matrix)
{
    // can get in linear time by comparing i[0]
    int max_ele = INT_MIN;
    for (int i = 0; i < matrix.size(); i++)
    {
        int last_col = matrix[i].size() - 1;
        max_ele = std::max(max_ele, matrix[i][last_col]);
    }
    return max_ele;
}

int checkHowManyElementsLessThanEqualToMid(const std::vector<std::vector<int>> &matrix, const int &mid)
{
    int count = 0;
    for (int i = 0; i < matrix.size(); i++)
    {
        count += std::upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin(); // takes logM time
    } // total takes nlogM
    return count;
}