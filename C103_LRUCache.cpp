#include <iostream>
#include <unordered_map>

using namespace std;

class Node
{
public:
    int key, val;
    Node *next;
    Node *prev;

    Node(int key, int val)
    {
        this->key = key;
        this->val = val;
        next = prev = NULL; // if we have conflicts so we can point with this-> but if no conflict we can directly use like we did with next and prev.....
    }
};

class LRUCache
{

    // hme ek cache system bnana h jisme 2 operation add karne h
    // get -> ye kya karega ek certain key ke liye val return karega
    // put -> ye certain key ke liye val add karega..

    // ab ye dono O(1) me karna h aur capacity of cache bhi h aur
    // jo bhi node add hogi wo head ke starting me hogi ya fir jo bhi val retrieve ya kuch bhi operation hoga the least recently used sabse aage chli jaegi and agar capacity ya limit poori hui to nyi add karne ke liye last delete hogi...

    // ab sabse pehle initialize kari apni cache aur dummy head tail daldiye with -1 key and val cache me use hogi dobly linked list and also ek map use karenge jo key ke hisab se us node ka address store karega..

    // ab hmne put function likha sabse pehle check kiya ki limit poori h to last ko delete kiya aur
    // fir check kiya agar us key ke liye h address map me to us node ko bhi delete karenge taki newnode aae aur val update ho jae...
    // ab simply apni nyi val head ke sath add kardi...

    // ab hmne get function likha isme kuch nhi karna check karenge if the map has no address for the key wo handle kiya
    // nhi to seedha pehle us node ko starting me shift kiya least recently used dikhane ke liye and return ki uski val....

public:
    Node *head;
    Node *tail;
    unordered_map<int, Node *> m;
    int limit;

    LRUCache(int limit)
    {
        if (limit < 1)
        {
            cout << "Limit Cannot be < 1";
            return;
        }
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
        this->limit = limit;
    }

    void deleteNode(Node *temp)
    {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;

        delete (temp);
    }

    void put(int k, int v)
    {

        if (m.find(k) != m.end())
        {
            deleteNode(m[k]);
            m.erase(k);
        }
        if (m.size() == limit)
        {
            m.erase(tail->prev->key);
            deleteNode(tail->prev);
        }

        Node *newNode = new Node(k, v);
        newNode->prev = head;
        newNode->next = head->next;
        head->next->prev = newNode;
        head->next = newNode;

        // puting in map m
        m[k] = newNode;
    }

    int get(int k)
    {
        if (m.find(k) == m.end())
        {
            return -1;
        }

        Node *temp = m[k];
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        temp->next = head->next;
        temp->prev = head;
        head->next->prev = temp;
        head->next = temp;

        return temp->val;
    }
};

int main()
{
    LRUCache cache(4);

    cache.put(6, 5);
    cache.put(9, 3);
    cache.put(22, 2);
    cache.put(44, 3);
    cache.put(3, 3);
    cache.put(5, 4);
    cache.put(3, 4);

    cout << "3 : " << cache.get(3) << endl;
    cout << "5 : " << cache.get(5) << endl;

    return 0;
}