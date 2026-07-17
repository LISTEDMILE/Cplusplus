#include <iostream>
#include <stack>

using namespace std;

class MinStack
{

    // pehle space complexity thi 2 n kyuki stack me 2 store karne pad rhe the ....

    // hm stack bnaenge val ke liye and minVal variable to store min..
    // push - agar pehli val h to push karo and min = val ho jaega..

    // if pehli nhi h to ab check karenge ki minVal se kam h kya agar ha to stack me sidha push karne ki jagah see formula below use karke push karenge jisse ab actual val chli jaegi minVal variable me aur stack me push hoga formule wali value...

    // aur gar val bdi h to simply push karenge..

    // ab pop ke time pe check karenge if the val on top minVal se bdi h to simple pop nhi to again formula se minVal to update karenge ......

    // top dekhne ke liye agar top minVal se kam h to original val h hmari minVal nhi to stack ka top.....
    stack<long long int> st;
    long long int minVal;

public:
    void push(int val)
    {
        if (st.empty())
        {
            st.push(val);
            minVal = val;
        }
        else
        {
            if (val < minVal)
            {
                st.push((long long int)2 * val - minVal);
                minVal = val;
            }
            else
            {
                st.push(val);
            }
        }
    }

    void pop()
    {
        if (st.top() < minVal)
        {
            minVal = 2 * minVal - st.top();
        }
        st.pop();
    }

    int top()
    {
        if (st.top() < minVal)
        {
            return minVal;
        }
        return st.top();
    }

    bool empty()
    {
        return st.empty();
    }

    int getMin()
    {
        return minVal;
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