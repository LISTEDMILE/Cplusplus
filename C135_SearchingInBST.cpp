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

Node *searchBST(Node *root, int val)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == val)
    {
        return root;
    }
    if (root->data > val)
    {
        return searchBST(root->left, val);
    }
    else
    {
        return searchBST(root->right, val);
    }
}

int main()
{

    // binary tree but left child have all nodes less than parent and right are always greater

    vector<int> arr = {3, 2, 1, 5, 6, 4};
    Node *root = buildBST(arr); // build BST binary search tree

    Node *sear = searchBST(root, 5);
    if (sear != NULL)
        cout << "Required Node data -> " << sear->data;
    else
        cout << "No node found";
    return 0;
}