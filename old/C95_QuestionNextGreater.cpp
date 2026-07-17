#include <iostream>
#include <stack>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> nextGreaterAccToParentArr(vector<int> arr, vector<int> parent)
{

    // ye ek application h of concept nextGreater of C94
    // yha hm kya karre ek arr h input aur ek parent arr h arr is subset of parent..
    // sare elements dono me unique..
    // ab hme ye karna h ki jo element arr me h unki parent array me nextgreater kya h search karke ek ans array return karni h..
    // yani elements arr ke par un elements ke next greater search karenge from parent...

    // ab kya kiya phel parent ke sabhi element ka nextGreater nikala aur ek map ki help se for each element uske corresponding next element ke sath store kiya...
    // fir ans arr me jo arr[j] ki val h usse map me corresponding nextgreater dekh aur ans me add kar diya.....

    stack<int> st;
    vector<int> ans(parent.size(), 0);
    unordered_map<int, int> m;

    for (int i = parent.size() - 1; i >= 0; i--)
    {
        while (st.size() > 0 && st.top() <= parent[i])
        {
            st.pop();
        }

        if (st.empty())
        {

            m[parent[i]] = -1;
        }
        else
        {

            m[parent[i]] = st.top();
        }

        st.push(parent[i]);
    }

    for (int j = 0; j < arr.size(); j++)
    {
        ans[j] = m[arr[j]];
    }

    return ans;
}

int main()
{

    vector<int> arr = {4, 2, 6, 9};
    vector<int> parent = {3, 6, 4, 2, 8, 9};
    vector<int> ans = nextGreaterAccToParentArr(arr, parent);

    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " - " << ans[i] << '\n';
    }
    return 0;
}