#include <iostream>
#include <vector>
#include <climits>

int bookAllocation(const std::vector<int> &input, const int &students);

int maxOfArray(const std::vector<int> &input);

int sumOfArray(const std::vector<int> &input);

bool checkIfAllStudentsGotTheBook(const std::vector<int> &input, const int &students, const int &answer);

int main()
{
    int size;
    std::cin >> size;
    std::vector<int> input(size);
    for (int i = 0; i < size; i++)
    {
        std::cin >> input[i];
    }
    int students;
    std::cin >> students;
    std::cout << bookAllocation(input, students) << "\n";
    return 0;
}

// minimize the maximum pages one student reads
// first true
// f f f f t t t t
int bookAllocation(const std::vector<int> &input, const int &students)
{
    if (students > input.size())
    {
        return -1;
    }
    int left = maxOfArray(input);  // minimum max pages that can be alloted to a student is the book with max pages
    int right = sumOfArray(input); // maximum max pages that can be allocated to a student is sum of pages of all the books
    int ans = -1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2; // our guess of max pages a student can read
        bool did_all_students_got_the_books = checkIfAllStudentsGotTheBook(input, students, mid);
        if (did_all_students_got_the_books)
        {
            ans = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return ans;
}

int maxOfArray(const std::vector<int> &input)
{
    int max_ele = INT_MIN;
    for (int i = 0; i < input.size(); i++)
    {
        if (input[i] > max_ele)
        {
            max_ele = input[i];
        }
    }
    return max_ele;
}

int sumOfArray(const std::vector<int> &input)
{
    int sum = 0;
    for (int i = 0; i < input.size(); i++)
    {
        sum += input[i];
    }
    return sum;
}

bool checkIfAllStudentsGotTheBook(const std::vector<int> &input, const int &students, const int &max_page_limit)
{
    int students_required = 1;
    int sum_of_pages = input[0];
    for (int i = 1; i < input.size(); i++)
    {
        if (sum_of_pages + input[i] > max_page_limit)
        {
            students_required++;
            sum_of_pages = input[i];
        }
        else
        {
            sum_of_pages += input[i];
        }
        // can't return early because all books should be allocated
    }
    if (students_required <= students)
    {
        return true;
    }
    return false;
}