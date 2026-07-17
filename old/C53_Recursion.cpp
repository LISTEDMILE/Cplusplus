#include <iostream>
#include <vector>

using namespace std;

int factorial(int n)
{
    if (n == 0)
    {
        return 1;
    }
    return n * factorial(n - 1);
}

void printNumbers(int n)
{ // recursive function
    if (n == 1)
    {
        cout << n; // base case
        return;
    }
    cout << n << " ";    // working
    printNumbers(n - 1); // self callback
}

int fibonacci(int a)
{
    if (a == 0)
    {
        return 0;
    }
    else if (a == 1)
    {
        return 1;
    }
    else
        return fibonacci(a - 1) + fibonacci(a - 2);
}

int binarySearch(vector<int> &arr, int tar, int st, int end)
{
    if (st <= end)
    {
        int mid = st + (end - st) / 2;
        if (arr[mid] == tar)
        {
            return mid;
        }
        else if (arr[mid] < tar)
        {
            return binarySearch(arr, tar, mid + 1, end);
        }
        else
        {
            return binarySearch(arr, tar, st, mid - 1);
        }
    }
    return -1;
}

int main()
{
    printNumbers(10);

    int n = 7;
    int fact = factorial(n);
    cout << "\nFactorial of " << n << " : " << fact << endl;

    cout << "Fibonacci : ";

    int a = 15;
    for (int i = 0; i < a; i++)
    {
        cout << fibonacci(i) << "  ";
    }

    vector<int> arr = {-1, 2, 4, 5, 6};
    int target = 5;
    int st = 0;
    int end = arr.size() - 1;
    int isPresent = binarySearch(arr, target, st, end);
    if (isPresent == -1)
    {
        cout << "\nThe value : " << target << " is not present";
    }
    else
        cout << "\nThe value : " << target << " is present at [" << isPresent << "]\n";
    return 0;
}