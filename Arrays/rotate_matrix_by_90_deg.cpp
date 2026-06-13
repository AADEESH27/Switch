#include <iostream>
#include <vector>
#include <algorithm>

void rotateMatrixBy90Deg(std::vector<std::vector<int>> &input);

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
    rotateMatrixBy90Deg(input);
    for (int i = 0; i < m; i++)
    {
#include <iostream>
#include <vector>
#include <algorithm>

        void rotateMatrixBy90Deg(std::vector<std::vector<int>> & input);

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
            rotateMatrixBy90Deg(input);
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    std::cout << input[i][j] << " ";
                }
                std::cout << "\n";
            }
            std::cout << "\n";
            return 0;
        }

        void rotateMatrixBy90Deg(std::vector<std::vector<int>> & input)
        {
            // Step 1 : Transpose
            for (int i = 0; i < input.size(); i++)
            {
                for (int j = 0; j < i; j++)
                {
                    std::swap(input[i][j], input[j][i]);
                }
            }
            // Step 2 : Reverse each row;
            for (int i = 0; i < input.size(); i++)
            {
                reverse(input[i].begin(), input[i].end());
            }
            return;
        }

        for (int j = 0; j < n; j++)
        {
            std::cout << input[i][j] << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
    return 0;
}

void rotateMatrixBy90Deg(std::vector<std::vector<int>> &input)
{
    // Step 1 : Transpose
    for (int i = 0; i < input.size(); i++)
    {
        for (int j = 0; j < i; j++)
        {
            std::swap(input[i][j], input[j][i]);
        }
    }
    // Step 2 : Reverse each row;
    for (int i = 0; i < input.size(); i++)
    {
        reverse(input[i].begin(), input[i].end());
    }
    return;
}
