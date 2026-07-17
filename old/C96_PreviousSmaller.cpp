#include <iostream>
#include <stack>
#include <vector>

using namespace std;

vector<int> prevSmaller(vector<int> arr)
{

    // same as nextGreater .....

    stack<int> st;
    vector<int> ans(arr.size(), 0);

    for (int i = 0; i < arr.size(); i++)
    {
        while (st.size() > 0 && st.top() >= arr[i])
        {
            st.pop();
        }

        if (st.empty())
        {
            ans[i] = -1;
        }
        else
        {
            ans[i] = st.top();
        }

        st.push(arr[i]);
    }
    return ans;
}

int main()
{

    vector<int> arr = {2, 6, 1, 0, 3, 2, 6, 9, 3};

    vector<int> ans = prevSmaller(arr);

    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " - " << ans[i] << '\n';
    }
    return 0;
}