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

    Node *MergeSortedLists(Node *l1, Node *l2)
    {
        // pehle bad wale if else dekho hm check karenge head me dono ke konsi value choti h lets supporse l1 wali choti h pehle call me matlab if condition execute ab matlab choti value l1 me h to head hmara l1 banna chahiye par ab head ka next kon bnega to uske liye Merge fucntion fir se call karent jo ki ab linked list lega jisme starting of l1 l1 -> next se hogi kyuki starting of l1 to head me already add kar diya to ab isme firse comparison same ab  firse dekhenge konsi choti h usko main bnaenge aur uske next me wo aaega jo merge function return karega same.....

        // base case agar ek linked list khatam ho jae to doosri wali aage as it is add kardenge.....

        if (l1 == NULL)
        {
            return l2;
        }

        else if (l2 == NULL)
        {
            return l1;
        }

        // Case 1
        if (l1->data < l2->data)
        {
            l1->next = MergeSortedLists(l1->next, l2);
            return l1;
        }

        // Case 2
        else
        {
            l2->next = MergeSortedLists(l1, l2->next);
            return l2;
        }
    }
};

int main()
{
    LL ll;
    ll.push_back(2);
    ll.push_back(3);
    ll.push_back(6);
    ll.push_back(7);

    cout << "\nll : \n";
    ll.display();

    LL ll2;
    ll2.push_back(2);
    ll2.push_back(4);
    ll2.push_back(5);
    ll2.push_back(8);
    ll2.push_back(9);

    cout << "\nll2 : \n";
    ll2.display();

    Node *sortedList = ll.MergeSortedLists(ll.head, ll2.head);

    cout << "\n\nMerged List:\n\nHEAD --> ";

    Node *temp = sortedList;

    while (temp != NULL)
    {
        cout << temp->data << " --> ";
        temp = temp->next;
    }

    cout << "NULL";

    return 0;
}