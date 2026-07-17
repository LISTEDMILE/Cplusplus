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

Node *insertNode(Node *root, int val)
{

    if (root == NULL)
    {
        Node *newNode = new Node(val);
        return newNode;
    }
    if (root->data > val)
    {
        root->left = insertNode(root->left, val);
    }
    else
    {
        root->right = insertNode(root->right, val);
    }
    return root;
}

Node *buildBST(vector<int> arr)
{
    Node *root = NULL;
    for (int val : arr)
    {
        root = insertNode(root, val);
    }
    return root;
}

Node *findInorderSuccessor(Node *root)
{
    while (root != NULL && root->left != NULL)
    {
        root = root->left;
    }
    return root;
}
Node *delNodeBST(Node *root, int val)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (root->data > val)
    {
        root->left = delNodeBST(root->left, val);
    }
    else if (root->data < val)
    {
        root->right = delNodeBST(root->right, val);
    }
    else
    { // in 2 if conditions me 0 child aur 1 child wala case ho gya...
        if (root->left == NULL)
        {
            Node *temp = root->right;
            delete (root);
            return temp;
        }
        if (root->right == NULL)
        {
            Node *temp = root->left;
            delete (root);
            return temp;
        }

        // 2 childs....
        Node *IS = findInorderSuccessor(root->right);
        root->data = IS->data;
        root->right = delNodeBST(root->right, IS->data);
        return root;
    }
    return root;
}

void inorderTraverseTree(Node *parent)
{

    if (parent == NULL)
    {

        return;
    }
    inorderTraverseTree(parent->left);
    cout << parent->data << ' ';

    inorderTraverseTree(parent->right);
}

int main()
{

    vector<int> arr = {3, 2, 1, 5, 6, 4};
    Node *root = buildBST(arr);

    delNodeBST(root, 1);

    cout << "In Order Traversal of Binary Search Tree : \n";
    inorderTraverseTree(root);
    return 0;
}