#include <iostream>
#include <vector>
#include <deque>

using namespace std;

vector<int> slidingWindowMaximum(vector<int> arr, int k)
{

    // hme kya karna h ki array ko k size ke hisab se lets say k= 4 to 4 4 ke hisab se subarrays consider karenge jise pehle iteration me pehle 4 fir pehla element chodke second se 5th tak ....
    // ab un sbke max element ko find karke nyi array me push karke return karna h..

    // ab hmne kya kiya pehli iteration ke liye alag loop chalaya k tak
    // jisme hm dekhenge jo deque ka size h wo jab tak ya to 0 na ho jae aur jab tak deque me jo index h back se check karte chlenge us index pe array ki value jo current index pe array ki value h usse choti honi chahiye tab tak ek ek element pop back karte rhenge
    // aise insliye taki hmari deque maintain ho ske wo bhi decreasing order me taki back se ek ek karke element nikal ske...

    // fir uske bad check karenge ki ab deque ke front me jo index h uspe is array me kya value h wo hmari us group ki max h usko ans me push karenge..

    // ab same hi kam k se aage wale elements ke liye ek ek karke karenge just the difference is ki ab hme ye bhi consider karna padega ki jo element deque me add ho rhe h agle iteration me agar ab wo current group ke part nhi to unko bhi pop kiya jae....

    // uske liye ye condition sahi rhegi d.front() pe jo index h wo current iteration se - group ke size se bhi pehle ka index h to matlab isko pop karo....
    deque<int> d;
    vector<int> ans;

    if (arr.size() < 1 || k > arr.size())
    {
        cout << "Invalid array size of group size";
        return ans;
    }
    for (int i = 0; i < k; i++)
    {
        while (d.size() > 0 && arr[d.back()] <= arr[i])
        {
            d.pop_back();
        }
        d.push_back(i);
    }

    ans.push_back(arr[d.front()]);

    for (int i = k; i < arr.size(); i++)
    {
        while (d.size() > 0 && d.front() <= i - k)
        {
            d.pop_front();
        }
        while (d.size() > 0 && arr[d.back()] <= arr[i])
        {
            d.pop_back();
        }
        d.push_back(i);
        ans.push_back(arr[d.front()]);
    }

    return ans;
}

int main()
{

    vector<int> arr = {2, 1, 6, -1, 3, -3, 5, 2, 4, 8, 6, 5};
    int k = 4;
    vector<int> ans = slidingWindowMaximum(arr, k);

    int idx = 0;
    for (int val : ans)
    {
        cout << "For { ";

        for (int i = idx; i < k + idx; i++)
        {
            cout << arr[i] << " , ";
        }
        cout << "} : ";
        idx++;

        cout << val << "\n";
    }
    return 0;
}