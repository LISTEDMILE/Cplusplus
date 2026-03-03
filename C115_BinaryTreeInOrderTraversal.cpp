#include <iostream>
#include <vector>

using namespace std;

///  building tree
// single node....
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
    if (idx >= arr.size()) // if invalid input given like left subtree given but right subtree tak aate me hi arr ke elements khatam fir.....
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

// Tree taversal ........

// Inorder traversal..
void inorderTraverseTree(Node *parent)
{

    if (parent == NULL)
    {
        cout << "N ";
        return;
    }

    inorderTraverseTree(parent->left);
    cout << parent->data << ' ';
    inorderTraverseTree(parent->right);
}

int main()
{
    vector<int> arr = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    int idx = -1;
    Node *root = buildTree(arr, idx);

    cout << "\n\nInorder Traversal : \n";
    inorderTraverseTree(root);

    cout << endl
         << endl;
    return 0;
}