#include <iostream>
#include <vector>

int ZScore(const std::vector<int> &input, int k);
bool checkIfSelectedNumberOfSubjectsIsFeasible(const std::vector<int> &input, const int k, const int number_of_subjects);

int main()
{
    int size;
    std::cin >> size;
    std::vector<int> input(size);
    for (int i = 0; i < input.size(); i++)
    {
        std::cin >> input[i];
    }
    int k;
    std::cin >> k;
    std::cout << ZScore(input, k) << "\n";
    return 0;
}

int ZScore(const std::vector<int> &input, int k)
{
    int low = 0;
    int high = input.size(); // all subjects passing
    int ans = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        bool is_selected_subjects_feasible = checkIfSelectedNumberOfSubjectsIsFeasible(input, k, mid);
        if (is_selected_subjects_feasible)
        {
            ans = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return ans;
}

bool checkIfSelectedNumberOfSubjectsIsFeasible(const std::vector<int> &input, const int k, const int number_of_subjects)
{
    int required_marks = k * number_of_subjects;
    int count = 0;
    for (int i = 0; i < input.size(); i++)
    {
        if (input[i] >= required_marks)
        {
            count++;
        }
        if (count >= number_of_subjects)
        {
            return true;
        }
    }
    return false;
}
