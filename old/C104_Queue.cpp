#include <iostream>
#include <vector>

using namespace std;

class Node
{
public:
    Node *next;
    int data;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

class QueueUsingLinkedList
{

    Node *head;
    Node *tail;

public:
    QueueUsingLinkedList()
    {
        head = tail = NULL;
    }

    void push(int val)
    {
        Node *newNode = new Node(val);
        if (empty())
        {

            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void pop()
    {
        if (empty())
        {
            cout << "Empty Queue";
            return;
        }
        Node *nextNode = head->next;
        delete (head);
        head = nextNode;
    }

    int front()
    {
        if (empty())
        {
            cout << "Empty Queue";
            return -1;
        }

        return head->data;
    }

    bool empty()
    {
        return head == NULL;
    }
};

int main()
{
    // entery from rear and pop from front....

    QueueUsingLinkedList q;
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