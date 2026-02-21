#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> calcSpan(vector<int> stock)
{

    // yha hm kya kar rhe ek array h stock usme hme ek ek element pe jana h aur check karna usme pehle kitne element tak sari values current se choti h..
    // means mano uske pehle ki 2 val choti h then bdi to 2 wo aur ek khud 3 span ho gya uska aur ha jo pehle bdi value mili uske pehle kya h usse matlab nhi h
    // to aise hi har val ka span save karna h

    // hmne kya kiya ek stack initialize kiya aur stock pe iteratin lga di aur check karre ki agar stack hmara empty nhi h aur jo val top pe h us index pe jo stock me value h wo ith index wali se kam h matlb stack se pop karte jaenge kyoki jitna pop karenge matlab utni kam iteration milegi stack me niche kyoki hm stack me index store karre val nhi
    // pop khatam tab hoga jab ya to stack khali ya koi bdi val mil gyi..
    // ab agar st empty h matlab wo val sabse hi bdi h abhi tak ke traverse me to uski span to total iteration +1 direct but if not empty then jo top of stack pe index h usko current index se minus karne pe hme no of span miljaega..
    // aur har iteration pe i ko push stack me karte hi rhenge ...........

    vector<int> span(stock.size(), 0);
    stack<int> st;
    for (int i = 0; i < stock.size(); i++)
    {
        while (st.size() > 0 && stock[st.top()] <= stock[i])
        {
            st.pop();
        }

        if (st.empty())
        {
            span[i] = i + 1;
        }
        else
        {
            span[i] = i - st.top();
        }
        st.push(i);
    }
    return span;
}

int main()
{
    vector<int> stock = {100, 59, 39, 58, 1000, 40};
    vector<int> span = calcSpan(stock);

    for (int val : span)
    {
        cout << val << ' ';
    }
    return 0;
}