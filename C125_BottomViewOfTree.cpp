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

void BottomViewOfTree(Node *parent)
{

    queue<pair<Node *, int>> q;
    map<int, Node *> m;
    int currHorizontalDistance = 0;
    q.push({parent, currHorizontalDistance});

    // ek while loop h aur unordered map nhi ordered map h to map ki time complexity O(long(n))
    // to TC => O(nlog(n))....
    while (!q.empty())
    {
        Node *curr = q.front().first;
        currHorizontalDistance = q.front().second;
        q.pop();

        m[currHorizontalDistance] = curr;

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

    // same as top view bottom  view print karna kuch nhi karenge jaise pehle if same horizontalDist ka koi aata tha to usko ignore karte the kyoki uper aa chuka already but isme jitni bar aaega update karte rhenge....

    vector<int> arr = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    int idx = -1;
    Node *root = buildTree(arr, idx);

    cout << "\nBottom view of Tree : \n";
    BottomViewOfTree(root);

    cout << endl;
    return 0;
}