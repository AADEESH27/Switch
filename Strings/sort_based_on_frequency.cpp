/*
This algo is the stepping stone for the concept of using unordered/ordered map(hashmap).
*/
#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>

auto sortStringByFrequency(const std::string &input, std::vector<char> &result) -> void;
auto custom_comparator(const std::pair<int, char> &a, const std::pair<int, char> &b) -> bool;

int main()
{
    std::string input;
    getline(std::cin, input);
    std::vector<char> result;
    sortStringByFrequency(input, result);
    for (char x : result)
    {
        std::cout << x << "\n";
    }
    return 0;
}

void sortStringByFrequency(const std::string &input, std::vector<char> &result)
{
    std::pair<int, char> freq_arr[26];
    for (int i = 0; i < 26; i++)
    {
        char alphabet = 'a' + i;
        char default_freq = 0;
        freq_arr[i] = {default_freq, alphabet};
    }
    for (int i = 0; i < input.size(); i++)
    {
        int index = input[i] - 'a';
        freq_arr[index].first++;
    }
    std::sort(freq_arr, freq_arr + 26, custom_comparator);
    for (int i = 0; i < 26; i++)
    {
        if (freq_arr[i].first != 0)
        {
            result.push_back(freq_arr[i].second);
        }
    }
    return;
}

bool custom_comparator(const std::pair<int, char> &a, const std::pair<int, char> &b)
{
    if (a.first > b.first)
        return true;
    else if (a.first < b.first)
        return false;
    return (a.second < b.second);
}