#include <iostream>
#include <vector>
#include <climits>

std::vector<int> peakElement(const std::vector<std::vector<int>> &matrix);
int rowWithMaxElement(const std::vector<std::vector<int>> &matrix, const int &col);

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
    std::vector<int> peak_element_index = peakElement(matrix);
    std::cout << matrix[peak_element_index[0]][peak_element_index[1]] << "\n";
    return 0;
}

std::vector<int> peakElement(const std::vector<std::vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    if (n * m == 1)
    {
        return {0, 0};
    }
    int low_col = 0;
    int high_col = m - 1;
    while (low_col <= high_col)
    {
        int mid_col = low_col + (high_col - low_col) / 2;
        int row_with_max_ele_for_mid_col = rowWithMaxElement(matrix, mid_col);
        int max_ele_for_mid_col = matrix[row_with_max_ele_for_mid_col][mid_col];
        int left = mid_col == 0 ? -1 : matrix[row_with_max_ele_for_mid_col][mid_col - 1];
        int right = mid_col == m - 1 ? -1 : matrix[row_with_max_ele_for_mid_col][mid_col + 1];
        if (max_ele_for_mid_col > left && max_ele_for_mid_col > right)
        {
            return {row_with_max_ele_for_mid_col, mid_col};
        }
        else if (left > max_ele_for_mid_col)
        {
            high_col = mid_col - 1;
        }
        else
        {
            low_col = mid_col + 1;
        }
    }
    return {-1, -1};
}

int rowWithMaxElement(const std::vector<std::vector<int>> &matrix, const int &col)
{
    int max_ele = INT_MIN;
    int row_with_max_ele = -1;
    for (int i = 0; i < matrix.size(); i++)
    {
        if (matrix[i][col] > max_ele)
        {
            max_ele = matrix[i][col];
            row_with_max_ele = i;
        }
    }
    return row_with_max_ele;
}