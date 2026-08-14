#include <iostream>
#include <vector>

bool searchInSortedMatrixII(const std::vector<std::vector<int>> &matrix, const int &target);

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
    int target;
    std::cin >> target;
    std::cout << searchInSortedMatrixII(matrix, target) << "\n";
    return 0;
}

bool searchInSortedMatrixII(const std::vector<std::vector<int>> &matrix, const int &target)
{
    int n = matrix.size();
    int m = matrix[0].size();
    int start_row = 0;
    int start_col = m - 1;
    while (start_row < n && start_col >= 0)
    {
        if (target == matrix[start_row][start_col])
        {
            std::cout << start_row << " " << start_col << "\n";
            return true;
        }
        else if (target > matrix[start_row][start_col])
        {
            start_row++;
        }
        else
        {
            start_col--;
        }
    }
    return false;
}