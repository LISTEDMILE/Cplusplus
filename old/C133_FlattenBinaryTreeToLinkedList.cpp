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

void FlattenTree(Node *parent, Node *&NR)
{
    if (parent == NULL)
        return;

    FlattenTree(parent->right, NR);
    FlattenTree(parent->left, NR);

    parent->left = NULL;
    parent->right = NR;
    NR = parent;
}

int main()
{

    // see hme kya karna ki preorder traversal wala jaise print kra te h na usi order me flatten ll bnani h same hi tree me i mean same nodes me left sabme null aur right ek linear manner me aur order perorder wala

    // ab hmne just simple preorder me jaise karte the usse ulta recursion lgaya pehle right ke liye fir left ke
    // aur uske bad jab sab call ja chuki hmne parent -> left = NULL kardiya kyuki traverse to already ho hi chuka
    // aur parent -> right = NR next right jo hm track kar rhe the ab ye global var h jo har call me change hota parent me
    // to right me NR aagya aur fir jaise bola NR ko parent me update.....

    vector<int> arr = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    int idx = -1;
    Node *root = buildTree(arr, idx);

    Node *NR = NULL; // NextRight matlab next rightt banne wala
    FlattenTree(root, NR);

    Node *temp = root;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->right;
    }

    cout << endl
         << endl;
    return 0;
}