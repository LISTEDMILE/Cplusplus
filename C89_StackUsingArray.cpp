#include <iostream>
#include <vector>

using namespace std;

class Stack
{
    vector<int> st;

public:
    void push(int val)
    {
        st.push_back(val);
    }

    void pop()
    {
        st.pop_back();
    }

    int top()
    {
        return st[st.size() - 1];
    }

    bool empty()
    {
        return st.size() == 0;
    }
};

int main()
{

    Stack s;
    s.push(8);
    s.push(2);
    s.push(7);

    while (!s.empty())
    {
        cout << (s.top()) << " ";
        s.pop();
    }

    return 0;
}