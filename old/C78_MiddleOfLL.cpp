#include <iostream>

using namespace std;

// we have to print the middle element
// middle if odd
// 2nd of 2 middles if size even

class Node
{
public:
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

class LL
{
public:
    Node *head;
    Node *tail;
    LL()
    {
        head = NULL;
        tail = NULL;
    }

    void push_back(int val)
    {

        Node *newNode = new Node(val);
        if (tail == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void display()
    {
        Node *current = head;
        cout << "\nHEAD --> ";
        while (current != NULL)
        {
            cout << (current->data) << " --> ";
            current = current->next;
        }
        cout << "NULL";
    }

    // brute force
    int middleElementBruteForce()
    {
        Node *current = head;
        int size = 0;
        while (current != NULL)
        {
            current = current->next;
            size++;
        }
        current = head;
        for (int i = 0; i < size / 2; i++)
        {
            current = current->next;
        }
        return current->data;
    }

    // slow fast approach
    int middleBySlowFast()
    {
        Node *slow = head;
        Node *fast = head;
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return (slow->data);
    }
};

int main()
{
    LL ll;
    ll.push_back(7);
    ll.push_back(4);
    ll.push_back(9);
    ll.push_back(7);
    ll.push_back(2);
    ll.push_back(7);
    ll.push_back(6);
    ll.push_back(4);
    ll.push_back(8);
    ll.push_back(5);

    ll.display();
    int ansBruteForce = ll.middleElementBruteForce();
    cout << "\n\nMiddle Element (BruteForce) = " << ansBruteForce;

    int ansSlowFast = ll.middleBySlowFast();
    cout << "\n\nMiddle Element (SlowFast) = " << ansSlowFast;
    return 0;
}