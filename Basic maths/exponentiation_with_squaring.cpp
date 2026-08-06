#include <iostream>

long long nPowerM(int n, int m)
{
    long long ans = 1;
    int base = m;
    while (n > 0)
    {
        if (n % 2 == 1)
        {
            ans *= base;
            n--;
        }
        else
        {
            base *= base;
            n /= 2;
        }
    }
    return ans;
}

int main()
{
    int n, m;
    std::cin >> n >> m;
    std::cout << nPowerM(n, m) << "\n";
    return 0;
}