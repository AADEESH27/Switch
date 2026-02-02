#include <iostream>
#include <vector>

int main()
{
    // Brute force
    // TC = O(n sqrt(n))
    // if (n == 2)
    //     return 1;
    // if (n == 3)
    //     return 2;
    // for (int i = 4; i <= n; i++)
    // {
    //     int flag = 0;
    //     code to find divisors too.
    //     for (int j = 2; j <= i / j; j++)
    //     {
    //         if (i % j == 0)
    //         {
    //             flag = 1;
    //         }
    //     }
    //     if (flag == 0)
    //         counter++;
    // }

    // Optimal
    // TC = O(n log log n)
    int input_number;
    std::cin >> input_number;
    std::vector<bool> is_prime(input_number + 1, true);
    is_prime[0] = false;
    is_prime[1] = false;
    // generally i * i <= input number but to prevent overflow of i * i we use the following method
    for (int i = 2; i <= input_number / i; i++) // n
    {
        if (is_prime[i] == true)
        {
            for (int j = i * i; j <= input_number; j += i) // n/i
            {
                is_prime[j] = false;
            }
        }
    }
    int counter = 0;
    for (bool prime : is_prime)
    {
        if (prime == true)
            counter++;
    }
    std::cout << counter << "\n";
    return 0;
}