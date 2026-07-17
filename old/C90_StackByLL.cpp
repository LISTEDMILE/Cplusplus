#include <iostream>
#include <vector>
#include <list>

using namespace std;

class Stack
{

    // we can create ll but in stl we have learned abt list which is class by C++ which is the implementation of ll

    list<int> st;

public:
    void push(int val)
    {

        // hme push back ki jagah front kiya taki stack ke top ko jo hmne head consider kiya h na to nya element agar back pe push karenge to top prev wale ko point karega but hme chahiye ki jo nya element aae top use point kare....
        st.push_front(val);
    }

    void pop()
    {
        st.pop_front();
    }

    int top()
    {
        // st.front() return head of the ll means top here
        return st.front();
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