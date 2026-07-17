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

    Node *reverseNodeInKGroup(Node *head, int k)
    {

        // hm kya karna chah rhe h ki poori ll ko k elements me devide karke har grp ko individual reverse karde aur agar k se kam h last wale grp me usko aise hi chod de..

        // ab isko recursion se karenge hmne sabse pehle check kiya ki loop k times chalne ke pehle temp null to nhi ho gya matlab last grp me k se kam to nhi aa rhe jaise 7 total ll elements h aur hmne 3 ke grps bnae to 3 3 = 6 last me 1 bacha to usko as it is return..

        // but if not then hmne recursion call kiya same fn ko assuming ki wo aage ki ll ko sahi karke sahi wali ka starting point return karega ..

        // fir hmne firse loop chalaya k tymes kyoki reverse karna h k elements ko
        // ab isme sabse pehle jo hmara jo curr head se start kiya jo ki uska next kya h matlab ki jo prev q me curr element h uska next kya tha tempPehleWalaNext var me store kara liya..
        // ab jo curr h uska next directly hmne point kara diya newNext ko initially newNext is theNext matlab jo starting of ll h recursion fn ne return kiya h bad me jo abhi curr h wo newNext bnega kyoki jab agla element reverse karenge to wo ise point karga..

        // aur ab hm curr ko tempPehleWalaNext le jaenge uske liye same cheeze repeat karne ke liye.
        //  return kardenge newNext ko kyoki ab last iteration ke bad it is the starting of ll......
        Node *temp = head;

        for (int i = 0; i < k; i++)
        {
            if (temp == NULL)
            {
                return head;
            }
            temp = temp->next;
        }

        Node *theNext = reverseNodeInKGroup(temp, k);

        Node *curr = head;
        Node *tempPehleWalaNext;
        Node *newNext = theNext;
        for (int i = 0; i < k; i++)
        {
            tempPehleWalaNext = curr->next;
            curr->next = newNext;
            newNext = curr;
            curr = tempPehleWalaNext;
        }

        return newNext;
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

    ll.head = ll.reverseNodeInKGroup(ll.head, 3);
    ll.print();

    return 0;
}