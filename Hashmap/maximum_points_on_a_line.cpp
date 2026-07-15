#include <iostream>
#include <vector>
#include <unordered_map>
#include <utility>
#include <climits>

struct pair_hash
{
    size_t operator()(const std::pair<int, int> &p) const
    {
        return std::hash<int>()(p.first) ^ (std::hash<int>()(p.second) << 1);
    }
};

int maxPointsOnALine(const std::vector<std::vector<int>> &input);

int getGCD(int a, int b);

int main()
{
    int size;
    std::cin >> size;
    std::vector<std::vector<int>> input;
    for (int i = 0; i < size; i++)
    {
        int x;
        int y;
        std::cin >> x >> y;
        input.push_back({x, y});
    }
    std::cout << maxPointsOnALine(input) << "\n";
    return 0;
}

int maxPointsOnALine(const std::vector<std::vector<int>> &input)
{
    if (input.size() == 1)
    {
        return 1;
    }
    if (input.size() == 2)
    {
        return 2;
    }
    int max_count = INT_MIN;
    for (int i = 0; i < input.size(); i++)
    {
        std::unordered_map<std::pair<int, int>, int, pair_hash> mp;
        for (int j = 0; j < input.size(); j++)
        {
            if (i == j)
            {
                continue;
            }
            int dy = input[j][1] - input[i][1];
            int dx = input[j][0] - input[i][0];
            if (dy == 0 && dx == 0)
            {
                continue;
            }
            if (dx < 0)
            {
                dy = -dy;
                dx = -dx;
            }
            int gcd = getGCD(std::min(abs(dy), abs(dx)), std::max(abs(dy), abs(dx)));
            dy = dy / gcd;
            dx = dx / gcd;
            auto it = mp.find({dy, dx});
            if (it != mp.end())
            {
                mp[{dy, dx}]++;
            }
            else
            {
                mp[{dy, dx}] += 2;
            }
            max_count = std::max(max_count, mp[{dy, dx}]);
        }
    }
    return max_count;
}

int getGCD(int a, int b)
{
    if (a == 0)
    {
        return b;
    }
    return getGCD(b % a, a);
}