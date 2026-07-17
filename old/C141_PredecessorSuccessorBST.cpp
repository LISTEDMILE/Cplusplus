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

Node *findPredecessor(Node *root)
{
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root;
}

Node *findSuccessor(Node *root)
{
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root;
}

vector<int> findPredecessorSuccessor(Node *root, int key)
{

    // dekho hme kya karna ki koi bhi val di ho key matlab uska predecessor aur successor btana h
    // pre matlab just chota succ matlab just bda
    // ab uske liye hmne while loop use kiya
    // ab 3 conditions h -

    // 1. if jo temp ka data h wo key se bda h matlab jo key h wo left me kahi milegi to abhi ke liye temp ko succ man liye aur usse pehle wale ko temp bna diya  taki yhi condition firse check kar ske ki kya hal h

    // 2. now if choti h data from key to ulta..

    // 3. if condition aati h bilkul equal hi ho gya to  to fir hm alag se uska predecessor aur successor nikalenge.......

    Node *temp = root;
    Node *pre = NULL;
    Node *suc = NULL;
    while (temp != NULL)
    {
        if (temp->data > key)
        {
            suc = temp;
            temp = temp->left;
        }
        else if (temp->data < key)
        {
            pre = temp;
            temp = temp->right;
        }
        else
        {
            if (temp->left != NULL)
            {
                pre = findPredecessor(temp->left);
            }
            if (temp->right != NULL)
            {
                suc = findSuccessor(temp->right);
            }
            break;
        }
    }
    return {pre != NULL ? pre->data : -1, suc != NULL ? suc->data : -1};
}

int main()
{

    vector<int> arr = {13, 8, 1, 5, 10, 16};
    Node *root = buildBST(arr);

    vector<int> ans = findPredecessorSuccessor(root, 6);

    cout << "Predecessor : " << ans[0] << "\nSuccessor : " << ans[1];
    return 0;
}