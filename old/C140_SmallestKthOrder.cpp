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

int SmallestKthElement(Node *parent, int k, int &order)
{

    // dekho hme kya karna kuch ni bas kth smallest element matlab agar kth element dekhe har kth usme se sabse chota
    // ab isko doosri tarah se dekho BST to sorted hote h inorder traversel me to hme bas kth element return karna h inorder traversal ka
    // bas to simple inorder traversal kar diya aur uske sath ek global variable order bnaya jo inorder me idx tack karta h ye man skte ho

    // ab dekha left se kuch ans aaya  agar ha to ans return
    // nhi to fir pehle order ++ karenge jo globally horha h
    //  root pe try karenge agar order kth h to retun
    // nhi to right me
    // kahi nhi mila to return -1;

    if (parent == NULL)
    {
        return -1;
    }
    if (parent->left)
    {
        int ansLeft = SmallestKthElement(parent->left, k, order);
        if (ansLeft != -1)
        {
            return ansLeft;
        }
    }

    order++;
    if (order == k)
    {
        return parent->data;
    }
    if (parent->right)
    {
        int ansRight = SmallestKthElement(parent->right, k, order);
        if (ansRight != -1)
        {
            return ansRight;
        }
    }
    return -1;
}

int main()
{

    vector<int> arr = {13, 8, 1, 5, 10, 16};
    Node *root = buildBST(arr);

    int order = 0;
    int ans = SmallestKthElement(root, 4, order);

    cout << "The kth smallest element is : " << ans;

    return 0;
}