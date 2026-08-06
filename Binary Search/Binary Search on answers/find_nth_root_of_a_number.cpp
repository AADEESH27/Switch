#include <iostream>
#include <cmath>

int findNthRootOfM(int &n, int &m);
int compareNthPower(int &mid, int &n, int &m);

int main()
{
    int n, m;
    std::cin >> n >> m;
    std::cout << findNthRootOfM(n, m);
    return 0;
}

int findNthRootOfM(int &n, int &m)
{
    int left = 1;
    int right = m;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        // long long nth_pow = std::pow(mid, n); // overflow is the main problem calculate mid^n iteratively and early return if ans gets > m
        int cmp = compareNthPower(mid, n, m);
        if (cmp == 0)
        {
            return mid;
        }
        else if (cmp == 1)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return -1;
}

int compareNthPower(int &mid, int &n, int &m)
{
    long long ans = 1;
    for (int i = 1; i <= n; i++)
    {
        ans *= mid;
        if (ans > m)
        {
            return 1;
        }
    }
    if (ans == m)
    {
        return 0;
    }
    return -1;
}