#include <iostream>
#include <queue>
using namespace std;

class Queue {
public:
    queue<int> q;

    Queue() {}

    bool isEmpty() {
        return q.empty();
    }

    void enqueue(int data) {
        q.push(data);
    }

    int dequeue() {
        if (q.empty())
            return -1;

        int ans = q.front();
        q.pop();
        return ans;
    }

    int front() {
        if (q.empty())
            return -1;

        return q.front();
    }
};

int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Front: " << q.front() << endl;     // 10

    cout << "Dequeued: " << q.dequeue() << endl; // 10
    cout << "Front: " << q.front() << endl;      // 20

    q.enqueue(40);

    while (!q.isEmpty()) {
        cout << q.dequeue() << " ";
    }

    cout << endl;

    cout << "Dequeue from empty queue: " << q.dequeue() << endl;
    cout << "Front of empty queue: " << q.front() << endl;

    return 0;
}