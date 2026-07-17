#include <iostream>
#include <stack>
#include <vector>

using namespace std;

vector<int> nextGreater(vector<int> arr)
{

    // same as nextGreater but isme agar last element h to usse bda dhoondne ke liye hm wapis start se shuru karenge matlab in short circular man ke karna...
    stack<int> st;
    vector<int> ans(arr.size(), 0);

    // hmne kya kiya arr ko ek bar traverse karne ki jagar 2 of size se 0 tak same kam kiya aur jha bhi index chahiye tha wha % use kiya isse array aise behave karegi jaise ki circular na ho linear ho aur sare elements 2 bar aae ho in same sequence
    // to jo 2*size se size tak ka iteration h usme kuch ans array banegi jo ki abhi poori sahi nhi h update hogi but is iteration se ye faeda hua ki jo hmara stack h usme jo curcular elements like jo elements repeat hue h uske hisab ki values already hmare stack me at least aa gyi.....

    for (int i = 2 * arr.size() - 1; i >= 0; i--)
    {

        while (st.size() > 0 && st.top() <= arr[i % arr.size()])
        {
            st.pop();
        }

        if (st.empty())
        {
            ans[i % arr.size()] = -1;
        }
        else
        {
            ans[i % arr.size()] = st.top();
        }

        st.push(arr[i % arr.size()]);
    }
    return ans;
}

int main()
{

    vector<int> arr = {2, 6, 1, 0, 3, 2, 6, 9, 3, 4, 3, 2, 1};

    vector<int> ans = nextGreater(arr);

    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " - " << ans[i] << '\n';
    }
    return 0;
}