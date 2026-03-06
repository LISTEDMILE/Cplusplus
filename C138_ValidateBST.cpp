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

// main function//////////..........

bool validateTree(Node *root, Node *min, Node *max)
{

    if (root == NULL)
    {
        return true;
    }

    if (min != NULL && min->data >= root->data)
        return false;
    if (max != NULL && max->data <= root->data)
        return false;

    return (validateTree(root->left, min, root) && validateTree(root->right, root, max));
}

int main()
{

    // dekho ab hme kya karna ki check karna ki ye ek valid bst h ya nhi
    // ab iske liye condition hoti h not only self right node but all child nodes in right either it is parent -> right ->left should be greater and left is lesser
    // ab ise check karne ke liye pehle hmne simple binary tree bnaya with random values jo return karega false
    // and ek hmne buildBST fn ka use karke proper BST bnaya uspe test kiya..

    // ab ye kam kaise karta h see hm dekhenge ki agar hmara if jo min h wo NULL nhi h kyukuaise bhi to ho skta h ki kisi node ke left me koi node ho hi na matlab wo kitni bhi choti val ho skti h
    // to if not null and min->data manlo bdi ho gyi jo curr root ki val h to return kareenge false seedha ..
    // same max ke sath

    // ab dono fail hui to recursion
    // return karenge
    // left ke liye is bar min same rhega aur jo max val ho jaegi wo root kyoki left jare h root ke to obvious root bda hi hona chahiye BST h
    // same rightt
    // and dono ka and karke seedha return  kyuki is bhi condn fail  false return seedha...
    vector<int> notValidArray = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    int idx = -1;
    Node *root = buildTree(notValidArray, idx);

    bool isValid = validateTree(root, NULL, NULL);

    if (isValid)
    {
        cout << "Given tree notValidArray wala is a valid tree";
    }
    else
    {
        cout << "Given tree notValidArray wala is not a valid tree";
    }

    cout << endl;

    vector<int> validArray = {3, 2, 1, 5, 6, 4};
    Node *rootValid = buildBST(validArray);

    bool isValidOfValidArray = validateTree(rootValid, NULL, NULL);

    if (isValidOfValidArray)
    {
        cout << "Given tree validArray wala is a valid tree";
    }
    else
    {
        cout << "Given tree validArray wala is not a valid tree";
    }

    cout << endl
         << endl;
    return 0;
}