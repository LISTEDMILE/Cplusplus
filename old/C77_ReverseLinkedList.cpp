#include <iostream>

using namespace std;

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

class List
{
    Node *head;
    Node *tail;

public:
    List()
    {
        head = tail = NULL;
    }

    void push_back(int val)
    {
        Node *newNode = new Node(val);
        // edge case - if empty list
        if (tail == NULL)
        {
            head = tail = newNode;
            return;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void reverse()
    {
        Node *nextt = NULL;
        Node *current = head;
        Node *prev = NULL;
        while (current != NULL)
        {

            nextt = current->next;
            current->next = prev;
            prev = current;
            current = nextt;
        }
        head = prev;
    }

    void print()
    {
        Node *temp = head;
        cout << "\nHEAD --> ";
        while (temp != NULL)
        {
            cout << (temp->data) << " --> ";
            temp = temp->next;
        }
        cout << "NULL";
    }
};

int main()
{

    List ll;

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

    ll.print();

    ll.reverse();
    ll.print();

    return 0;
}