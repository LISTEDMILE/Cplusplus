#include <iostream>

using namespace std;

class CircularQueue
{
    int *arr;
    int currSize, capacity;
    int fr, rear;

public:
    CircularQueue(int size)
    {
        capacity = size;
        currSize = 0;
        fr = 0;
        rear = -1;
        arr = new int[capacity]; // created new array of integer with given capacity...
    }

    void push(int val)
    {

        if (isFull())
        {
            cout << "Queue Full\n";
            return;
        }
        rear = (rear + 1) % capacity;
        arr[rear] = val;
        currSize++;
    }

    int front()
    {
        if (empty())
        {
            cout << "Queue Empty";
            return -1;
        }
        return arr[fr];
    }

    void pop()
    {
        if (empty())
        {
            cout << "Queue Empty";
            return;
        }
        fr = (fr + 1) % capacity;
        currSize--;
    }

    bool empty()
    {
        return currSize == 0;
    }

    bool isFull()
    {
        return currSize == capacity;
    }
};

int main()
{
    CircularQueue c(8);
    c.push(1);
    c.push(2);
    c.push(3);
    c.push(4);
    c.push(5);
    c.push(6);
    c.push(7);
    c.push(8);

    while (!c.empty())
    {
        cout << c.front() << " ";
        c.pop();
    }

    return 0;
}