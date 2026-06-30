#include <bits/stdc++.h>
using namespace std;

/*
    Function: findArraySum

    Given two arrays representing two numbers,
    return their sum as another array.

    Example:
    a = {1, 2, 3}
    b = {9, 9}

    123 + 99 = 222

    Output:
    {2, 2, 2}
*/

vector<int> findArraySum(vector<int> &a, int n, vector<int> &b, int m)
{

    vector<int> ans;
    int carry = 0;

    // Process both arrays from the last digit
    while (!a.empty() && !b.empty())
    {

        // Get the last digit
        int x = a.back();
        int y = b.back();

        // Remove the processed digit
        a.pop_back();
        b.pop_back();

        // Current digit of the answer
        ans.push_back((x + y + carry) % 10);

        // Carry for the next iteration
        carry = (x + y + carry) / 10;
    }

    // Process remaining digits of array a
    while (!a.empty())
    {

        int x = a.back();
        a.pop_back();

        ans.push_back((x + carry) % 10);
        carry = (x + carry) / 10;
    }

    // Process remaining digits of array b
    while (!b.empty())
    {

        int y = b.back();
        b.pop_back();

        ans.push_back((y + carry) % 10);
        carry = (y + carry) / 10;
    }

    // If carry still exists, add it
    if (carry)
        ans.push_back(carry);

    // Digits were added from right to left,
    // so reverse to get the correct order
    reverse(ans.begin(), ans.end());

    return ans;
}

int main()
{

    vector<int> a = {1, 2, 3};
    vector<int> b = {9, 9};

    vector<int> ans = findArraySum(a, a.size(), b, b.size());

    cout << "Sum = ";

    for (int digit : ans)
        cout << digit;

    cout << endl;

    return 0;
}