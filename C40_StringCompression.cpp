#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

vector<char> compresss(vector<char> a)
{

    int idx = 0;
    for (int i = 0; i < a.size();)
    {
        char ch = a[i];
        int count = 0;
        while (i < a.size() && a[i] == ch)
        {
            count++;
            i++;
        }
        if (count == 1)
        {
            a[idx++] = ch;
        }
        else
        {
            a[idx++] = ch;
            string str = to_string(count);
            for (char dig : str)
            {
                a[idx++] = dig;
            }
        }
    }
    // it will remove extra junks after idx....
    a.resize(idx);
    return a;
}

int main()
{

    vector<char> chars = {'a', 'a', 'b', 'b', 'c', 'c', 'c'};

    vector<char> b = compresss(chars);

    cout << "The reverse string : ";
    for (char val : b)
    {
        cout << val << " ";
    }

    return 0;
}
