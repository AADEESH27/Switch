#include <iostream>
int arr[10000000];
int main()
{
    int input_1, input_2;
    std::cin >> input_1 >> input_2;
    int smaller_number = std::min(input_1, input_2);
    int larger_number = std::max(input_1, input_2);
    int iterator = 1;
    while (true)
    {
        int multiple = larger_number * iterator;
        if (multiple % input_1 == 0 && multiple % input_2 == 0)
        {
            std::cout << "LCM = " << multiple;
            break;
        }
        iterator++;
    }
    std::cout << "\n";
    while (smaller_number != 0)
    {
        int r = smaller_number;
        smaller_number = larger_number % smaller_number;
        larger_number = r;
    }
    std::cout << "LCM = " << (input_1 * input_2) / larger_number;
    return 0;
}