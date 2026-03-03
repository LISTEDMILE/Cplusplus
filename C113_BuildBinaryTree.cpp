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

// preorder traversal..
void preorderTraverseTree(Node *parent)
{

    if (parent == NULL)
    {
        cout << "N ";
        return;
    }
    cout << parent->data << ' ';
    preorderTraverseTree(parent->left);
    preorderTraverseTree(parent->right);
}

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

// postorder traversal..
void postorderTraverseTree(Node *parent)
{

    if (parent == NULL)
    {
        cout << "N ";
        return;
    }
    cout << parent->data << ' ';
    postorderTraverseTree(parent->right);
    postorderTraverseTree(parent->left);
}

int main()
{

    //// basics....

    // it is a form of tree data structure which can have at max 2 nodes
    // the starting node is call root node
    // there is left child child which is the left side node
    // a right child which is on right child
    // the node which has these right and left child are parent node
    // there are leaf nodes which have 0 child node
    // connecting two nodes is called branches
    // 2 nodes at same node are called neighbour
    // 2 nodes of same parent node at same level are sibling node
    // the no of node between root node and the longest path from root to leaf
    // if the left child prepare a whole new tree it is called left subTree and same with right...

    // build a tree using preorder sequence....

    // here -1 means NULL node..
    vector<int> arr = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    int idx = -1;
    Node *root = buildTree(arr, idx);

    cout << endl
         << endl;
    return 0;
}