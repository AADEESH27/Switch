#include <iostream>
#include <vector>

int rowsWithMax1s(const std::vector<std::vector<int>> &matrix);

int main()
{
    int row, col;
    std::cin >> row >> col;
    std::vector<std::vector<int>> matrix(row, std::vector<int>(col, 0));
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            std::cin >> matrix[i][j];
        }
    }
    std::cout << rowsWithMax1s(matrix) << "\n";
    return 0;
}

int rowsWithMax1s(const std::vector<std::vector<int>> &matrix)
{
    int max_1s = 0;
    int row_with_max_1s = -1;
    for (int i = 0; i < matrix.size(); i++)
    {
        int j = matrix[i].size() - 1;
        if (matrix[i][j] == 0)
        {
            continue;
        }
        // upper bound of 0
        int low = 0;
        int high = j;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (matrix[i][mid] < 1)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        int count = j + 1 - low;
        if (count > max_1s)
        {
            max_1s = count;
            row_with_max_1s = i;
        }
    }
    return row_with_max_1s;
}