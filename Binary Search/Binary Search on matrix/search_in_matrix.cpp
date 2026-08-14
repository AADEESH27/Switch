#include <iostream>
#include <vector>

bool searchInSortedMatrix(const std::vector<std::vector<int>> &matrix, const int &target);

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
    std::cout << searchInSortedMatrix(matrix, target) << "\n";
    return 0;
}

bool searchInSortedMatrix(const std::vector<std::vector<int>> &matrix, const int &target)
{
    int n = matrix.size();
    int m = matrix[0].size();
    int low = 0;
    int high = n * m - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int row = mid / m;
        int col = mid % m;
        if (matrix[row][col] == target)
        {
            return true;
        }
        else if (matrix[row][col] > target)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return false;
}