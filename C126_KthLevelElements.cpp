#include <iostream>
#include <vector>

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

void printKthLevel(Node *parent, int level)
{

    if (parent == NULL)
    {

        return;
    }

    if (level == 1)
    {
        cout << parent->data << ' ';
        return;
    }
    printKthLevel(parent->left, level - 1);
    printKthLevel(parent->right, level - 1);
}

int main()
{

    // hme kth level ke elements ko print karana to simply hmne ek val bhi dal diya recursion me jo every child node jane pe ek ek kam hoga aur jaise hi 1 ho jaega matlab desired level pe aa gya usko print kara denge aur recursion to bas left aur right dono me chlega hi....
    vector<int> arr = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    int idx = -1;
    Node *root = buildTree(arr, idx);

    int level = 1;

    cout << level << "th level : ";
    printKthLevel(root, level);

    cout << endl
         << endl;
    return 0;
}