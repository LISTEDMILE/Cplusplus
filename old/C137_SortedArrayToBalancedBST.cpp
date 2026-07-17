#include <iostream>
#include <vector>
#include <queue>

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

Node *buildBalancedBSTFromSortedArray(vector<int> &arr, int st, int end)
{
    if (st > end)
    {
        return NULL;
    }
    int mid = st + (end - st) / 2;
    Node *root = new Node(arr[mid]);
    root->left = buildBalancedBSTFromSortedArray(arr, st, mid - 1);
    root->right = buildBalancedBSTFromSortedArray(arr, mid + 1, end);
    return root;
}

void levelorderTraverseTree(Node *parent)
{

    queue<Node *> q;
    q.push(parent);
    q.push(NULL);
    while (!q.empty())
    {
        Node *curr = q.front();
        q.pop();

        if (curr == NULL)
        {
            if (!q.empty())
            {
                cout << endl;
                q.push(NULL);
            }
            else
            {
                break;
            }
        }
        else
        {
            cout << curr->data << " ";

            if (curr->left != NULL)
                q.push(curr->left);

            if (curr->right != NULL)
                q.push(curr->right);
        }
    }
}

int main()

{
    // hme kya karna ki hme ek sorted array given h ab isme hme ek balanced BST bnana h matlab balanced max distance b\w heights of different leaf nodes me sirf ek ka difference hona chahiye
    // ab uske liye simple dimag lgaya ki middle of array se start kiya apna build karna tree
    // mid ka root bnaya
    // left me firse call dalke left array ka bnaya aur root -> left me dal diya
    // same with right.....
    vector<int> arr = {-3, -2, 0, 1, 4, 5, 7};
    int idx = -1;
    Node *root = buildBalancedBSTFromSortedArray(arr, 0, arr.size() - 1);

    cout << "\n\nLevel Order Traversal : \n";
    levelorderTraverseTree(root);

    cout << endl
         << endl;
    return 0;
}