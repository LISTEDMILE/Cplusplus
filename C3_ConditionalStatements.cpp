#include <iostream>
using namespace std;

int main()
{
    int a;
    cout << "Enter a no.: ";
    cin >> a;
    if (a > 0)
    {
        cout << "a : " << a << " is positive" << "\n";
    }
    else if (a == 0)
    {
        cout << "a : " << a << " is 0" << "\n";
    }
    else
    {
        cout << "a : " << a << " is negative " << "\n";
    }

    // to find char is lower case or upper case

    char b;
    cout << "Enter a character : ";
    cin >> b;
    if (b >= 'a' && b <= 'z')
    {
        cout << "lowercase";
    }
    else
    {
        cout << "uppercase";
    }

    // same can be done with ternary statements
    cout << "\n"
         << ((b >= 'a' && b <= 'z') ? "lowercase" : "uppercase") << "\n";

    return 0;
}