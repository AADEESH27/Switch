#include <iostream>

auto getGCD(int n1, int n2) -> int;
int main()
{
    int n1 = 6;
    int n2 = 12;

    // Brute force
    // TC = O(n)
    int gcd = 1;
    for (int i = 1; i <= std::min(n1, n2); i++)
    {
        if (n1 % i == 0 && n2 % i == 0)
        {
            gcd = i;
        }
    }
    std::cout << gcd << "\n";

    // Better = Euclidian algorithm
    // TC = O(logn)
    // std::cout << getGCD(std::min(n1, n2), std::max(n1, n2)) << "\n";

    // Optimal
    while (n1 != 0)
    {
        int r = n1;
        n1 = n2 % n1;
        n2 = r;
    }
    std::cout << n2 << "\n";
    return 0;
}

int getGCD(int n1, int n2)
{
    if (n1 == 0)
    {
        return n2;
    }
    return getGCD(n2 % n1, n1);
}