#include <iostream>
#include <unordered_map>

using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node *random;
    Node(int val)
    {
        data = val;
        next = NULL;
        random = NULL;
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

    void display(Node *start)
    {
        Node *current = start;
        cout << "\n\nHEAD --> ";
        while (current != NULL)
        {
            cout << (current->data) << " --> ";
            current = current->next;
        }
        cout << "NULL";

        cout << "\nRandom pointers : \n";

        current = start;
        while (current != NULL)
        {
            if (current->random)
                cout << (current->data) << " --> " << (current->random->data) << "    -    ";
            current = current->next;
        }
    }

    Node *CopyList()
    {

        // at first we will create a simple ll asuming it is a normal linear linked list by copyting it like this..
        // newHead create kiya ab old temp ko ek ek bhda te gye aur newTemp ko ekk bhda te gye aur newtemp ke next me ek copyNode bnake dalte gye jo ki oldTemp ki copy h....

        if (head == NULL)
        {
            return NULL;
        }

        Node *newHead = new Node(head->data);
        Node *oldTemp = head->next;
        Node *newTemp = newHead;
        while (oldTemp != NULL)
        {
            Node *copyNode = new Node(oldTemp->data);
            newTemp->next = copyNode;
            newTemp = newTemp->next;
            oldTemp = oldTemp->next;
        }

        unordered_map<Node *, Node *> pair;

        oldTemp = head;
        newTemp = newHead;
        while (oldTemp != NULL)
        {
            pair.insert({oldTemp, newTemp});
            oldTemp = oldTemp->next;
            newTemp = newTemp->next;
        }

        oldTemp = head;
        newTemp = newHead;
        while (oldTemp != NULL)
        {
            newTemp->random = pair[oldTemp->random];
            oldTemp = oldTemp->next;
            newTemp = newTemp->next;
        }

        return newHead;
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

    ll.head->random = ll.head->next->next; // 7 -> 9 for making randoms
    ll.head->next->random = ll.head;       // 4 -> 7

    ll.display(ll.head);

    Node *copyList = ll.CopyList();

    ll.display(copyList);

    return 0;
}