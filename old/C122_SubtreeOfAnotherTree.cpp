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

bool isIdentical(Node *root1, Node *root2)
{

    // we have to check if the 2 trees are very same
    // ab hmne recursion ka use kiya jisme hmne 3 var bnae areRootSame matlab jo actual val h wo same h
    // isLeftIdentical ye ek recursion call dalega jo btaega kya left subtree identical h
    // isRightIdentical ye same btaega ki kya right subtree identical h

    // ab hm return kardenge true if 3no bate true h otherwise false..

    ///// ab ending casess
    // hm check karenge ki agar wo last NULL nodes tak pohoch chuka h kya agar dono NULL ho gye h yani same hi h NULL == NULL true so return true but agar aisa nhi h aur koi bhi ek NULL ho gya matlab fir to ek NULL h aur ek nhi to matlab different h dono to return false.....

    if (root1 == NULL && root2 == NULL)
    {
        return true;
    }
    if (root1 == NULL || root2 == NULL)
    {
        return false;
    }

    bool areRootSame = (root1->data == root2->data);
    bool isLeftIdentical = isIdentical(root1->left, root2->left);
    bool isRightIdentical = isIdentical(root1->right, root2->right);

    return (areRootSame && isLeftIdentical && isRightIdentical);
}

bool isSubTreeOf(Node *root, Node *subtree)
{
    if (root == NULL)
    {
        return false;
    }
    if (root->data == subtree->data && isIdentical(root, subtree))
    {
        return true;
    }

    return (isSubTreeOf(root->left, subtree) || isSubTreeOf(root->right, subtree));
}

int main()
{
    vector<int> arr1 = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    vector<int> arr2 = {3, 4, -1, -1, 5, -1, -1};
    int idx = -1;
    Node *root1 = buildTree(arr1, idx);

    idx = -1;
    Node *root2 = buildTree(arr2, idx);

    bool isSubTree = isSubTreeOf(root1, root2);

    if (isSubTree)
    {
        cout << "Second tree is subtree of tree1";
    }
    else
    {
        cout << "Second tree is not a subtree of tree1";
    }
    return 0;
}