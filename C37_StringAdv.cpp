#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

// palindrome/.....

bool isAlphaNumeric(char c)
{
    if ((c >= '0' && c <= '9') || (tolower(c) >= 'a' && tolower(c) <= 'z'))
        return true;

    return false;
}

bool palin(string a)
{
    int st = 0;
    int end = a.length() - 1;
    while (st < end)
    {
        if (!isAlphaNumeric(a[st]))
        {
            st++;
            continue;
        }
        if (!isAlphaNumeric(a[end]))
        {
            end--;
            continue;
        }
        if (tolower(a[st]) != tolower(a[end]))
        {
            return false;
        }
        st++;
        end--;
    }
    return true;
}

/// occurance ...../.....

string removeOcc(string b, string c)
{
    // .find(c) matlab usme c ka starting index ,, return large int if not found...
    while (b.length() > 0 && b.find(c) < b.length())
    {
        // erase will remove the part starting from first parameter to the length in second....

        b.erase(b.find(c), c.length());
    }
    return b;
}

int main()
{

    // check string palindrome
    string a;
    getline(cin, a);
    bool isPalindrome = palin(a);
    if (isPalindrome)
        cout << "The string " << a << " is Palindrome " << endl;
    else
        cout << "The string " << a << " is not Palindrome " << endl;

    // remove all occurances like aacbabcd remove abc new string is aacbd now check in this....
    string b;
    string c;
    cout << "Enter test string : ";
    getline(cin, b);
    cout << "Enter occurance to remove : ";
    getline(cin, c);
    string ans = removeOcc(b, c);
    cout << "The string after removing " << c << " = " << ans << endl;

    return 0;
}