#include <iostream>
using namespace std;

int main()
{
    // while loop
    int a = 0;
    while (a <= 10)
    {
        cout << a << "\t";
        a += 1;
    }

    cout << "\n\n";

    // for loop
    a = 0;
    for (a; a <= 10; a++)
    {
        cout << a << "\t";
    }

    cout << "\n\n";

    // do While loop
    a = 0;
    do
    {
        cout << a << "\t";
        a++;
    } while (a <= 10);

    cout << "\n\n";

    // prime no found with optimization
    int prime;
    cout << "Enter a no. : \n";
    cin >> prime;
    bool isPrime = true;
    for (int i = 2; i * i <= prime; i++)
    {
        if (prime % i == 0)
        {
            isPrime = false;
            break;
        }
    }
    if (isPrime)
    {
        cout << prime << " is a Prime no. \n";
    }
    else
    {
        cout << prime << " is a non-Prime no. \n";
    }

    return 0;
}