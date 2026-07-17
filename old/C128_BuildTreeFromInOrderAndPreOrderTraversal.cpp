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

int searchInOrder(int target, vector<int> &inorder, int left, int right)
{

    for (int i = left; i <= right; i++)
    {
        if (inorder[i] == target)
        {
            return i;
        }
    }
    return -1;
}

Node *buildTreeFromPreAndInOrder(vector<int> &preorder, vector<int> &inorder, int &preIdx, int left, int right)
{
    if (left > right)
    {
        return NULL;
    }

    Node *root = new Node(preorder[preIdx]);

    int inOrIdx = searchInOrder(preorder[preIdx], inorder, left, right);

    preIdx++;

    root->left = buildTreeFromPreAndInOrder(preorder, inorder, preIdx, left, inOrIdx - 1);
    root->right = buildTreeFromPreAndInOrder(preorder, inorder, preIdx, inOrIdx + 1, right);

    return root;
}

void preorderTraverseTree(Node *parent)
{

    if (parent == NULL)
    {
        return;
    }
    cout << parent->data << ' ';
    preorderTraverseTree(parent->left);
    preorderTraverseTree(parent->right);
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

    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};

    int preIdx = 0;
    Node *root = buildTreeFromPreAndInOrder(preorder, inorder, preIdx, 0, inorder.size() - 1);

    cout << "Inorder : ";
    preorderTraverseTree(root);

    cout << "\nPreorder : ";
    inorderTraverseTree(root);

    cout << endl
         << endl;
    return 0;
}