#include <iostream>
#include <vector>
#include <utility>

class Hashmap
{
private:
    std::vector<std::vector<std::pair<int, int>>> block{10};

public:
    void insert(int key, int value);
};

void Hashmap::insert(int key, int value)
{
    int hash_value = key % block.size();
    std::vector<std::pair<int, int>> *temp = &block[hash_value];
    bool key_present = false;
    for (int i = 0; i < (*temp).size(); i++)
    {
        if ((*temp)[i].first == key)
        {
            (*temp)[i] = {key, value};
            key_present = true;
        }
    }
    if (!key_present)
    {
        block[hash_value].push_back({key, value});
    }
}
int main()
{
    return 0;
}