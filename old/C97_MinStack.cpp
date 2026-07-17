#include <iostream>
#include <stack>

using namespace std;

class MinStack
{

    // hme har val ke sath us level tak ki min val bhi store karni h taki use O(1) me min return kari ja ske..

    stack<pair<int, int>> st; // <val, minimum value at that level>

public:
    void push(int val)
    {
        if (st.empty())
        {
            st.push({val, val});
        }
        else
        {
            int minVal = min(st.top().first, val);
            st.push({val, minVal});
        }
    }

    void pop()
    {
        st.pop();
    }

    int top()
    {
        return st.top().first;
    }

    bool empty()
    {
        return st.empty();
    }

    int getMin()
    {
        return st.top().second;
    }
};

int main()
{

    MinStack m;

    m.push(7);
    m.push(4);
    m.push(0);
    m.push(-1);
    m.push(8);

    cout << "Min val : " << m.getMin() << '\n';

    while (!m.empty())
    {
        cout << m.top() << " ";
        m.pop();
    }

    return 0;
}