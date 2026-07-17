#include <iostream>
#include <stack>
#include <vector>

using namespace std;

vector<int> nextGreater(vector<int> arr)
{

    // hme kya karna h ki jo bhi hmara element h usse right me chalte jaenge jo pehle greater mila wo ans array me same index pe rakh dena agar nhi mila to -1..

    // ab hmne kya kiya loop ko ulta chalaya aur check kiya sabse pehle ki kya stack khali nhi h and top arr[i] se chota h jab tak true h top se pop karte rho taki jo first larger ho wha tak pohoch jae waise bhi ulta loop chal rha h..

    // ab agar empty ho gya apna stack to ans[i] me -1..
    // if not to ans[i] me jo stack ke top pe yani pehla greater element...
    // aur ha har iteration pe st me arr[i] push karna nhi bhoolna....
    stack<int> st;
    vector<int> ans(arr.size(), 0);

    // time and space complexity....
    // yha pe space complexity to O(n) hogi kyoki stack me max n elements store kra rhe.
    // time complexity me lag skta h ki nested loop h but clearly dekhe to inner loop max n times hi chal skta h sari for loop ki iteration milake bhi kyuki sare elements atmost ek bar hi push pop ho skte h...
    // to time complexity O(n)....
    for (int i = arr.size() - 1; i >= 0; i--)
    {
        while (st.size() > 0 && st.top() <= arr[i])
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

    vector<int> ans = nextGreater(arr);

    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " - " << ans[i] << '\n';
    }
    return 0;
}