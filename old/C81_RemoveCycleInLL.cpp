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

    bool RemoveCycle()
    {

        // ek ek karke slow ko 1 se aur fast ko 2 se bhdate jaenge ab ya to fast null tak jaega matlab no cycle ya fast slow equal matlab cycle....

        // ab starting of cycle dhoondenge if cycle h to slow ko firse head tak jana hoga wha se is bar fast aur slow dono 1 se bhdenge jha meet kiye whi se cycle start.....

        // ab ham ek prev pointer bhi maintain karenge to jab hm starting of cycle par pohoche to prev starting of cycle ke pichle ko point karega jiska prev -> next hm NULL kar denge......
        Node *slow = head;
        Node *fast = head;

        bool isCyclic = false;
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
            {
                isCyclic = true;
                break;
            }
        }

        if (!isCyclic)
        {
            return false;
        }

        slow = head;
        Node *prev;
        while (slow != fast)
        {
            slow = slow->next;
            prev = fast;
            fast = fast->next;
        }

        prev->next = NULL;
        return true;
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

    ll.tail->next = ll.head->next->next; // creating cycle at node with value 9 to check cycle
    cout << "\n check code if the cycle is given or not\n";

    bool isCyclic = ll.RemoveCycle();

    if (!isCyclic)
    {
        cout << "\nNo Cycle";
    }
    else
    {
        cout << "\n Cycle Removed : \n";
    }

    ll.display();

    return 0;
}