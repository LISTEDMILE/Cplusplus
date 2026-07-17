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

int SumTree(Node *parent)
{
    if (parent == NULL)
    {
        return 0;
    }

    int leftSum = SumTree(parent->left);
    int rightSum = SumTree(parent->right);
    int totalSum = leftSum + rightSum + parent->data;

    parent->data = totalSum;
    return totalSum;
}

int main()
{

    // simple question h hme har node pe store karna h sum of its own value + left subtree whole values + right

    // to hmne recursion ke through assume kiya leftSum me left sum return hoga
    // right ke liye call kiya wha right ka sum reutrn hoga
    // dono ko own ki value me add karke update kardi same node ki val and also return kar diya abhi tak ka total sum taki ye sum recursion ke liye kisi ka leftSum ya rightSum ki tarah return ho jae.....
    vector<int> arr = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    int idx = -1;
    Node *root = buildTree(arr, idx);

    SumTree(root);

    cout << "The desired Sum Tree : ";
    preorderTraverseTree(root);

    cout << endl
         << endl;
    return 0;
}