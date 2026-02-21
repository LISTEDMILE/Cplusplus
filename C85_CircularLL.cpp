#include <iostream>

using namespace std;

class Node
{

public:
    int data;
    Node *next;

    Node(int val)
    {
        this->data = val;
        this->next = NULL;
    }
};

class CircularLL
{

    Node *head;
    Node *tail;

public:
    CircularLL()
    {
        this->head = this->tail = NULL;
    }

    void push_front(int val)
    {

        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = tail = newNode;
            head->next = head;
        }
        else
        {
            newNode->next = head;
            head = newNode;
            tail->next = newNode;
        }
    }

    void push_back(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = tail = newNode;
            head->next = head;
        }
        else
        {
            tail->next = newNode;
            newNode->next = head;
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
        else if (head == tail)
        {
            delete head;
            head = tail = NULL;
        }
        else
        {
            Node *temp = head;
            head = head->next;

            tail->next = head;

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
        else if (head == tail)
        {
            delete head;
            head = tail = NULL;
        }
        else
        {
            Node *temp = tail;

            Node *findPrev = tail;

            while (findPrev->next != tail)
            {
                findPrev = findPrev->next;
            }

            findPrev->next = head;

            delete temp;
        }
    }

    void display()
    {
        Node *temp = head;
        cout << "\nHead --> ";
        if (temp != NULL)
        {

            cout << temp->data << " --> ";
            temp = temp->next;
            while (temp != head)
            {
                cout << temp->data << " --> ";
                temp = temp->next;
            }
        }
        cout << "NULL";
    }
};

int main()
{

    CircularLL cll;

    cll.push_back(7);
    cll.push_back(4);
    cll.push_back(9);
    cll.push_back(7);
    cll.push_back(2);
    cll.push_front(7);
    cll.push_front(6);
    cll.push_front(4);
    cll.push_front(8);
    cll.push_front(5);

    cll.display();
    cout << "\n\nDelete first : ";
    cll.pop_front();
    cll.display();

    cout << "\n\nDelete last : ";
    cll.pop_back();
    cll.display();

    return 0;
}