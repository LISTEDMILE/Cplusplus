#include <iostream>
#include <queue>

using namespace std;

class Stack
{

    queue<int> s;
    queue<int> temp;

public:
    void push(int val)
    {

        while (!s.empty())
        {
            temp.push(s.front());
            s.pop();
        }

        s.push(val);
        while (!temp.empty())
        {
            s.push(temp.front());
            temp.pop();
        }
    }

    void pop()
    {
        s.pop();
    }

    int top()
    {
        return s.front();
    }

    bool empty()
    {
        return s.empty();
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