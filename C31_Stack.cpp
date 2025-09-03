#include <iostream>
#include <stack>
using namespace std;

int main()
{

    // LIFO
    stack<int> s;

    s.push(1);
    s.push(2);
    s.push(3);

    cout << "The top element : " << s.top();

    s.pop();
    cout << "\nThe top element after deletion : " << s.top();

    cout << "\nIs Stack s Empty : " << s.empty();

    stack<int> s2;
    s2.swap(s);

    return 0;
}