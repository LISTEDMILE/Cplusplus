#include <iostream>
#include <stack>
#include <string>
#include <unordered_set>

using namespace std;

bool isValid(string s)
{

    stack<char> st;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '{' || s[i] == '[' || s[i] == '(')
        { // opening brackets
            st.push(s[i]);
        }
        else
        {
            if (st.size() == 0)
            {
                return false;
            }

            if ((s[i] == '}' && st.top() == '{') || (s[i] == ']' && st.top() == '[') || (s[i] == ')' && st.top() == '('))
            {
                st.pop();
            }
            else
            {
                return false;
            }
        }
    }

    if (st.size() == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{

    string s = "{[()]()}";

    cout << (isValid(s) ? " is valid." : " is invalid.");

    return 0;
}