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

    bool isCyclic()
    {
        Node *slow = head;
        Node *fast = head;
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
            {
                return true;
            }
        }
        return false;
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

    bool isCyclicc = ll.isCyclic();
    if (isCyclicc)
    {
        cout << "\nThe list is cyclic.";
    }
    else
    {
        cout << "\nThe list is not cyclic.";
    }

    return 0;
}