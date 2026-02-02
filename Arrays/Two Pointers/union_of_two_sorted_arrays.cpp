#include <iostream>
#include <vector>

int main()
{
    int n1[5] = {1, 1, 3, 5, 5};
    int n2[3] = {1, 2, 2};
    int s_f = 0;
    int e_f = 4;
    int s_s = 0;
    int e_s = 2;
    std::vector<int> temp;
    temp.push_back(std::min(n1[0], n2[0]));
    while (s_f <= e_f && s_s <= e_s)
    {
        if (n1[s_f] <= n2[s_s])
        {
            if (temp.back() != n1[s_f])
            {
                temp.push_back(n1[s_f]);
            }
            s_f++;
        }
        else
        {
            if (temp.back() != n2[s_s])
            {
                temp.push_back(n2[s_s]);
            }
            s_s++;
        }
    }
    while (s_f <= e_f)
    {
        if (temp.back() != n1[s_f])
        {
            temp.push_back(n1[s_f]);
        }
        s_f++;
    }
    while (s_s <= e_s)
    {
        if (temp.back() != n2[s_s])
        {
            temp.push_back(n2[s_s]);
        }
        s_s++;
    }
    for (int x : temp)
    {
        std::cout << x << " ";
    }
    return 0;
}