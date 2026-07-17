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

    void push_front(int val)
    {
        Node *newNode = new Node(val);
        // edge case - if empty list
        if (head == NULL)
        {
            head = tail = newNode;
            return;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
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

    void pop_front()
    {
        // edge case - empty list
        if (head == NULL)
        {
            cout << "\nEmpty List";
            return;
        }
        Node *temp = head;
        head = head->next;
        delete temp;
    }

    void pop_back()
    {
        // edge case - if no node..
        if (head == NULL)
        {
            cout << "\nEmpty List";
            return;
        }

        // edge case - if ony one node.
        if (head->next == NULL)
        {
            delete head;
            head = tail = NULL;
            return;
        }

        Node *temp = head;
        while (temp->next != tail)
        {
            temp = temp->next;
        }
        temp->next = NULL;
        delete tail;
        tail = temp;
    }

    void insert(int val, int pos)
    {
        Node *newNode = new Node(val);
        Node *temp = head;

        if (pos < 0)
        {
            cout << "\nInvalid index";
            return;
        }

        // edge case - if pos == 0;
        if (pos == 0)
        {
            push_front(val);
            return;
        }

        for (int i = 0; i < pos - 1; i++)
        {
            temp = temp->next;
            // edge case - if pos is greater than len of ll.
            if (temp == NULL)
            {
                cout << "\nInsufficient Length";
                return;
            }
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    int searching(int val)
    {
        int idx = -1;
        Node *temp = head;
        while (temp != NULL)
        {
            idx++;
            if (temp->data == val)
            {
                return idx;
            }
            temp = temp->next;
        }
        return -1;
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
    ll.print();

    ll.push_front(4);
    ll.push_front(5);
    ll.push_front(6);
    ll.push_front(5);
    ll.push_front(6);
    ll.print();

    ll.push_back(7);
    ll.push_back(4);
    ll.push_back(9);
    ll.push_back(7);
    ll.push_back(4);
    ll.print();

    ll.pop_front();
    ll.print();
    ll.pop_back();
    ll.print();

    ll.insert(0, 5);
    ll.print();

    int ele = 4;
    int search = ll.searching(ele);
    if (search != -1)
    {
        cout << "\n"
             << ele << " is present at idx : " << search << " .";
    }
    else
    {
        cout << "\n"
             << ele << " is not present.";
    }

    return 0;
}