#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string> input);

int main()
{
    int size;
    std::cin >> size;
    std::vector<std::string> input(size);
    for (int i = 0; i < size; i++)
    {
        std::string inp;
        std::cin >> inp;
        input.push_back(inp);
    }
    std::vector<std::vector<std::string>> result = groupAnagrams(input);
    for (int i = 0; i < result.size(); i++)
    {
        for (int j = 0; j < result[i].size(); j++)
        {
            std::cout << result[i][j] << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
    return 0;
}

std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string> input)
{
    std::unordered_map<std::string, std::vector<std::string>> mp;
    for (int i = 0; i < input.size(); i++)
    {
        std::string temp = input[i];
        std::sort(temp.begin(), temp.end()); // klogk
        auto it = mp.find(temp);
        if (it != mp.end())
        {
            it->second.push_back(input[i]);
        }
        else
        {
            mp[temp].push_back(input[i]);
        }
    }
    // nklogk
    std::vector<std::vector<std::string>> result;
    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        std::vector<std::string> temp;
        for (int i = 0; i < it->second.size(); i++)
        {
            temp.push_back(it->second[i]);
        }
        result.push_back(temp);
    }
    // nk(if size of grouped vector is k)
    return result;
}