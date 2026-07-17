#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

bool isFreqSame(int freq1[], int freq2[])
{
    for (int i = 0; i < 26; i++)
    {
        if (freq1[i] != freq2[i])
        {
            return false;
        }
    }
    return true;
}

bool checkInclusion(string a, string b)
{

    int freq[26] = {0};
    for (int i = 0; i < a.length(); i++)
    {

        // a[i] se wo letter milega to jab do character ko - karenge to wo unki ascii value ka subtraction return karega.. like here lets say a[i] = a so a ki value asli nhi h par man lo 75 to 75 - 75 0 index pe frequency ek bhad jaegi lets say b h to fir b ki 76 to 76-75 = 1 to index 1 pe ek frequency bhad jaegi aisi hi sabhi char h freq array me;;......
        int idx = a[i] - 'a';
        freq[idx]++;
    }

    int windSize = a.length();
    for (int i = 0; i < b.length(); i++)
    {
        int windIdx = 0, idx = i;
        int windFreq[26] = {0};

        while (windIdx < windSize && idx < b.length())
        {
            windFreq[b[idx] - 'a']++;
            windIdx++;
            idx++;
        }

        if (isFreqSame(freq, windFreq))
        {
            return true;
        }
    }
    return false;
}

int main()
{
    string a, b;
    cout << "Enter string to search : ";
    getline(cin, a);
    cout << "Enter string to search from : ";
    getline(cin, b);
    bool ans = checkInclusion(a, b);
    cout << "By any occurance : " << endl;
    if (ans)
    {
        cout << "The string " << a << " is present in " << b;
    }
    else
    {
        cout << "The string " << a << " is not present in " << b;
    }

    return 0;
}