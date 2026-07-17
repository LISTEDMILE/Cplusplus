#include <iostream>
#include <set>
using namespace std;

int main()
{

    // used to store unique values
    set<int> s;

    s.insert(3);
    s.insert(2);
    s.insert(1);
    s.insert(4);
    s.insert(6);
    s.insert(7);
    s.insert(8);

    s.insert(2);
    s.insert(3);
    s.insert(4);

    for (auto p : s)
    {
        cout << p << "\t";
    }

    // provide element equal or just larger
    cout << "\ns.lower_bound(3) = " << *(s.lower_bound(3));
    cout << "\ns.lower_bound(5) = " << *(s.lower_bound(5));
    // if no element
    //   {unexpected error coming } cout << "\ns.lower_bound(10) = " << *(s.lower_bound(9));

    // provide element just larger...
    cout << "\ns.upper_bound(7) = " << *(s.upper_bound(7));

    // same here multiset for allow duplicated and uordered with random ordered///......

    return 0;
}