#include <iostream>
#include <deque>

using namespace std;

int main()
{
    // same as queue just in this we can do push back and front and pop also and read also from both side basically.....

    deque<int> q;
    q.push_back(3);
    q.push_back(4);
    q.push_front(5);
    q.push_front(6);
    q.push_front(7);

    cout << "\nFront : ";

    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop_front();
    }

    q.push_back(3);
    q.push_back(4);
    q.push_front(5);
    q.push_front(6);
    q.push_front(7);

    cout << "\nBack : ";

    while (!q.empty())
    {
        cout << q.back() << " ";
        q.pop_back();
    }

    return 0;
}