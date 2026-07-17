#include <iostream>
#include <vector>
#include <cstring>

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

void findPaths(Node *parent, vector<string> &ans, string path)
{

    path = path + " --> " + to_string(parent->data);

    if (parent->left == NULL && parent->right == NULL)
    {
        ans.push_back(path);
        return;
    }

    if (parent->left != NULL)
        findPaths(parent->left, ans, path);
    if (parent->right != NULL)
        findPaths(parent->right, ans, path);
}

int main()
{

    // hme kya karna ki jitne bhi possible path h na root se leaf tak pohochne ke un sabko ke array me dalna
    // ab hmne kya kiya ki recursion use kiya
    // base case agar left right dono null yani ki leaf node aa gyi to jo path h hmara usko ans me push
    // now actual recursion dekho if parent -> left h to uske liye ek call aur hmne path already parent node usme daldi h to aage jo bhi path hoga wo us path me concat hota rhega jab tak leaf node na aa jae..
    // same hoga right ke liye....
    vector<int> arr = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    int idx = -1;
    Node *root = buildTree(arr, idx);

    vector<string> ans;
    findPaths(root, ans, "");

    for (string val : ans)
    {
        cout << val << endl;
    }

    cout << endl
         << endl;
    return 0;
}