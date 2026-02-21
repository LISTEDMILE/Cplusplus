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

public:
    Node *head;
    Node *tail;

    List()
    {
        head = tail = NULL;
    }

    void push_back(int val)
    {
        Node *newNode = new Node(val);
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

    void SwapNodesInPairs()
    {

        // hme kya karna ki 2 2 ke pair bnane aur unko swap karna each grp ke liye if 1 element bacha to aise hi aa jaega
        // ab hmne kya kiya ki ek condition check kri ki loop tab tak chle jab tak temp bhi exist kare aur uska next bhi
        // uske bad first second me 2 elements of grp rakhe then afterSecond me second ka next rakha ab temp ki jarurat nhi to simply temp ko 2 step aage le gye kyuki operation sare 2 grp tak hi honge usse aage wala safe h aur temp ko increament bhi karna h
        // ab second ke next me first dala
        // first ke next me afterSecond dala jisse imagine hmare 2no swap to ho gye but jo before first jo pehle first pointer tha jo pointer use point karta tha usko change karna hoga
        // ek situation agar sabse pehle iteration ho to hmara beforeTemp NULL ko point karega  to usko hm first ko point karenge waise position dekhe to ll me wo 2nd element h ab update ke bad but pointer first h  usko point kiya aur first iteration me to head bhi cahnge karenge to the second pointer jo actuallly me ab 1st position me ll me ...

        // agar first iteratin nhi h matlab beforeTemp == NULL nhi h to beforeTemp -> next point karega second pointer ko jo ki actually me ab 1st position me h  aur beforeTemp me dalenge first jo actually second position me h aur ye fir next iteration me beforeFirst ki tarah behave karega.......

        Node *temp = head;
        Node *beforeTemp = NULL;

        while (temp != NULL && temp->next != NULL)
        {

            Node *first = temp;
            Node *second = temp->next;
            Node *afterSecond = temp->next->next;
            temp = temp->next->next;
            second->next = first;
            first->next = afterSecond;
            if (beforeTemp == NULL)
            {

                beforeTemp = first;
                head = second;
            }
            else
            {

                beforeTemp->next = second;
                beforeTemp = first;
            }
        }
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

    ll.SwapNodesInPairs();
    ll.print();

    return 0;
}