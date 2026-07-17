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

Node *findInorderPredecessor(Node *curr)
{
    Node *temp = curr->left;
    while (temp->right != NULL && temp->right != curr)
    {
        temp = temp->right;
    }

    return temp;
}

void MorrisInorderTraverseTree(Node *curr)
{

    // dekho simple inorder taverse karna bina recursion ke ab hmne kya kiya
    // dekho imagine karo ek tree kisme left chiild nhi h right right jate jare to inorder traverse karna kitna aasan data print aur pointer right me move karte rho
    // ab dekho hmne kya check kiya ki curr -> left NUll agar h to matlab uper wala scenerio but bas ek node ke liye to seedha data print and curr ko right me bhek diya
    /// ab else me
    // sabse pehle inorderPredecessor nikalenge ab check karenge if agar inorder predecessor ka right NULL h matlab hmna abhi tak use nhi chua dekho hm kya karre is case me ek bar ip me curr jo h na jiske liye wo ip h us hisab se ip->right me curr karre to agar wo null h matlab pehli bar h hmne abhi tak uska right nhi apply kiya..
    // to abhi tak NULL h to usko curr se connect karenge ip->right = curr
    // aur fir aaram se curr = curr-> left move karskte h kyoki ab ip ke pas pehle curr jo tha wha pohochne ka pointer h
    // ab if ip-> right == NULL nhi hota to usko null kardete ki bhai ab 2nd time aae h ab tera kam ho gya  aur seedha curr -> data print karao aur curr -> right wale pe move ho jao....
    while (curr != NULL)
    {
        if (curr->left == NULL)
        {
            cout << curr->data << " ";
            curr = curr->right;
        }
        else
        {
            Node *IP = findInorderPredecessor(curr);
            if (IP->right == NULL)
            {
                IP->right = curr;
                curr = curr->left;
            }
            else
            {
                IP->right = NULL;
                cout << curr->data << " ";
                curr = curr->right;
            }
        }
    }
}

int main()
{
    vector<int> arr = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    int idx = -1;
    Node *root = buildTree(arr, idx);

    cout << "\n\nMorris Inorder Traversal : \n";
    MorrisInorderTraverseTree(root);

    cout << endl
         << endl;
    return 0;
}