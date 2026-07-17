#include <iostream>
#include <queue>
using namespace std;

int main(){

    // FIFO
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);

    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    // baki swap wagerah sab same work karenge.....
    

    return 0;
}