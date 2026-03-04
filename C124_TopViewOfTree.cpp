#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        left = right = NULL;
        data = val;
    }
};

Node *buildTree(vector<int> &arr, int &idx)
{
    idx++;
    if (idx >= arr.size())
    {
        cout << "Invalid input , preorder sequence";
        return NULL;
    }
    if (arr[idx] == -1)
        return NULL;
    Node *parentNode = new Node(arr[idx]);
    parentNode->left = buildTree(arr, idx);
    parentNode->right = buildTree(arr, idx);
    return parentNode;
}

void TopViewOfTree(Node *parent)
{

    // dekho jo horizontal traversal wala logic tha wo use hoga
    // ab hm kya karenge sabse pehli iteration manually karenge jisme hmne queue create kiya q usme push karenge is bar {node parent node aur , currHorizontalDistance =0}
    // ab basically karna kya chah rhe ki ek map hmne create kiya m usme hm is tarah store karenge map(node, horizontalDistance)
    // horizontal distance is basically see jo root node h uska 0 fir uska left -1 uska bhi left -2 aise hi right 1 uska bhi right 2 ab root ke right ka left = 0 + 1 -1 = 0 samjhe

    // to ab hm loop chalaenge jab tak hamri q empty nhi ho jati
    // q ke front ko fetch kiya uska horiDist capture kiya
    // usko pop kar diya
    // ab check karenge ki m me kya ye horizontalDist wala koi exist karta h if( yes) to matlab uske uper koi to element aa gya to kuch nhi
    // agar kuch exist nhi karta to usko map me dalenge.....

    // aur same jaise horizontalTraverse me karte the left aur right me traverse karenge aur unpe bhi same logic...

    // last me fir map se order wise print kara denge sare elements waise bhi map h isme order hota h.....

    queue<pair<Node *, int>> q;
    map<int, Node *> m; // map not unordered map because we need order...
    int currHorizontalDistance = 0;
    q.push({parent, currHorizontalDistance});

    while (!q.empty())
    {
        Node *curr = q.front().first;
        currHorizontalDistance = q.front().second;
        q.pop();

        if (m.find(currHorizontalDistance) == m.end())
        {
            m[currHorizontalDistance] = curr;
        }

        if (curr->left != NULL)
            q.push({curr->left, currHorizontalDistance - 1});

        if (curr->right != NULL)
            q.push({curr->right, currHorizontalDistance + 1});
    }

    for (auto i : m)
    {
        cout << i.second->data << " ";
    }
}

int main()
{
    // hme kya karna ki ab jo tree h usko uper se kaisa dikhega wo dekhna

    vector<int> arr = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    int idx = -1;
    Node *root = buildTree(arr, idx);

    cout << "\nTop view of Tree : \n";
    TopViewOfTree(root);

    cout << endl;
    return 0;
}