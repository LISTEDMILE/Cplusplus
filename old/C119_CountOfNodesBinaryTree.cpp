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

int NoOfNodes(Node *root)
{

    if (root == NULL)
    {
        return 0;
    }

    int NoOfNodesInLeft = NoOfNodes(root->left);
    int NoOfNodesInRight = NoOfNodes(root->right);
    return NoOfNodesInLeft + NoOfNodesInRight + 1;
}

int main()
{
    vector<int> arr = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    int idx = -1;
    Node *root = buildTree(arr, idx);

    int count = NoOfNodes(root);
    cout << "Total no. of Nodes : " << count;
    return 0;
}