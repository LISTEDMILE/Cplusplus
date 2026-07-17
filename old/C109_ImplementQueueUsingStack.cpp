#include <iostream>
#include <stack>

using namespace std;

class Queue
{

    stack<int> q;
    stack<int> temp;

public:
    void push(int val)
    {
        while (!q.empty())
        {
            temp.push(q.top());
            q.pop();
        }

        q.push(val);

        while (!temp.empty())
        {
            q.push(temp.top());
            temp.pop();
        }
    }

    void pop()
    {
        q.pop();
    }

    int front()
    {
        return q.top();
    }

    bool empty()
    {
        return q.empty();
    }
};

int main()
{

    Queue q;
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    q.push(7);

    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}