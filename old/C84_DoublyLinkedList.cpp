#include <iostream>

using namespace std;

class Node
{

public:
    int data;
    Node *prev;
    Node *next;

    Node(int val)
    {
        this->data = val;
        this->prev = this->next = NULL;
    }
};

class DoublyLL
{

    Node *head;
    Node *tail;

public:
    DoublyLL()
    {
        this->head = this->tail = NULL;
    }

    void push_front(int val)
    {

        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void push_back(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void pop_front()
    {
        if (head == NULL)
        {
            cout << "Empty LL";
            return;
        }
        else
        {
            Node *temp = head;
            head = head->next;
            if (head != NULL)
            {
                head->prev = NULL;
            }

            delete temp;
        }
    }

    void pop_back()
    {
        if (head == NULL)
        {
            cout << "Empty LL";
            return;
        }
        else
        {
            Node *temp = tail;
            tail = tail->prev;
            if (tail != NULL)
            {
                tail->next = NULL;
            }

            delete temp;
        }
    }

    void displayFromNext()
    {
        Node *temp = head;

        cout << "\nHead --> ";
        while (temp != NULL)
        {
            cout << temp->data << " --> ";
            temp = temp->next;
        }
        cout << "NULL";
    }

    void displayFromPrev()
    {
        Node *temp = tail;

        cout << "\nTail --> ";
        while (temp != NULL)
        {
            cout << temp->data << " --> ";
            temp = temp->prev;
        }
        cout << "NULL";
    }
};

int main()
{

    DoublyLL dll;

    dll.push_back(7);
    dll.push_back(4);
    dll.push_back(9);
    dll.push_back(7);
    dll.push_back(2);
    dll.push_front(7);
    dll.push_front(6);
    dll.push_front(4);
    dll.push_front(8);
    dll.push_front(5);

    dll.displayFromNext();
    dll.displayFromPrev();

    cout << "\n\nDelete first : ";
    dll.pop_front();
    dll.displayFromNext();

    cout << "\n\nDelete last : ";
    dll.pop_back();
    dll.displayFromNext();

    return 0;
}