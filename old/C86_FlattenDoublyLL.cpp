#include <iostream>

using namespace std;

class Node
{

public:
    int data;
    Node *prev;
    Node *next;
    Node *child;

    Node(int val)
    {
        this->data = val;
        this->child = NULL;
        this->prev = this->next = NULL;
    }
};

class MultiLevelDoublyLL
{

public:
    Node *head;
    Node *tail;

    MultiLevelDoublyLL()
    {
        this->head = this->tail = NULL;
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

    Node *flattenLL(Node *currHead)
    {

        // hme yha pe simple dll hoti h jaise waise hi h but multiple dll hongi jisme sabme except the last one kisi ek node me child pointer hoga jo usse niche wali ke head ko point karega..

        // ab hme sabse pehli dll ko traverse karna h simply start se end tak ek ek karke simply but if the condition ki kisi node me child node h to .
        // hm  us node ke child se mtlb next node ke head se jo same hi h recurrsion recall karenge jo ki return karega hmara is dll ke head ko jisko hm rkhenge curr ->next me jisse abhi tak hmari dll me 2 dll join ho gyi but the child jiske pass tha uske bad wali list abhi aise hi pdi h jiska starting at least theNext pointer me h..
        // curr ka child ab null kardiya kyuki already  connected..
        // fir ab koi child pointer dobara to nhi aane wala to ek while loop lgaenge ki curr  = curr -> next ....
        /// fir jo bachi h child ke bad agar wo offcourse null nhi h to usko aage jodenge theNext pointer ki help se as hmare pas tail to h hi mtlb curr = curr ->next karte karte end to h hi...

        Node *curr = currHead;
        while (curr != NULL)
        {
            if (curr->child != NULL)
            {
                Node *theNext = curr->next;
                curr->next = flattenLL(curr->child);
                curr->next->prev = curr;
                curr->child = NULL;

                while (curr->next != NULL)
                {
                    curr = curr->next;
                }

                if (theNext != NULL)
                {
                    theNext->prev = curr;
                    curr->next = theNext;
                }
            }
            else
            {
                curr = curr->next;
            }
        }
        return currHead;
    }

    void display()
    {
        Node *temp = head;

        cout << "\nHead --> ";
        while (temp != NULL)
        {
            cout << temp->data << (temp->child ? " [parent]" : "") << " --> ";
            temp = temp->next;
        }
        cout << "NULL";
    }
};

int main()
{

    MultiLevelDoublyLL dll;
    MultiLevelDoublyLL dll2;
    MultiLevelDoublyLL dll3;
    MultiLevelDoublyLL dll4;

    dll.push_back(7);
    dll.push_back(4);
    dll.push_back(9);
    dll.push_back(7);
    dll.push_back(2);

    dll2.push_back(7);
    dll2.push_back(5);
    dll2.push_back(4);
    dll2.push_back(0);

    dll3.push_back(8);
    dll3.push_back(1);
    dll3.push_back(3);
    dll3.push_back(6);

    dll4.push_back(5);
    dll4.push_back(9);
    dll4.push_back(4);
    dll4.push_back(1);

    dll.head->next->next->next->child = dll2.head;
    dll2.head->next->next->child = dll3.head;
    dll3.head->next->child = dll4.head;

    dll.display();
    dll2.display();
    dll3.display();
    dll4.display();

    dll.flattenLL(dll.head);

    dll.display();

    return 0;
}