#include <iostream>
#include <vector>
using namespace std;

bool isValid(vector<int> books, int mid, int studentCount)
{
    int sum = 0;
    int count = 1;
    for (int i = 0; i < books.size(); i++)
    {
        if (mid < books[i])
        {
            return false;
        }
        else if (mid >= sum + books[i])
        {
            sum += books[i];
        }
        else
        {
            sum = books[i];
            count++;
            if (count > studentCount)
            {
                return false;
            }
        }
    }
    return true;
}

int minOfMaxAllocation(vector<int> books, int studentCount)
{
    int sum = 0;
    for (int val : books)
    {
        sum += val;
    }
    int start = 0;
    int end = sum;
    int ans;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (isValid(books, mid, studentCount))
        {
             ans = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return ans;
}

int main()
{

    // all books should be allocated.
    // all students should have at least one.
    // books are alloted in contiguous manner.

    // calculate min of ( lets suppose in some case a gets 30 and b gets 40 than max of both 40 )
    //  matlab min value nikalni h maximum alloatments ki....

    vector<int> books = {10, 20, 30, 40};
    int studentCount = 2;
    int ans = minOfMaxAllocation(books, studentCount);
    cout << ans;

    return 0;
}