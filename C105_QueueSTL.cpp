#include <iostream>
#include <queue>

using namespace std;

int main()
{
    // entery from rear and pop from front....

    queue<int> q;
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    q.push(7);

    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}