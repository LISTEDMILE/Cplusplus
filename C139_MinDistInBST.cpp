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

int minDistance(Node *parent, Node *&prev)
{

    // dekho hme min distance dhoondna h kisi bhi do nodes me se
    // ab dekho BST sorted to hote hi h inorder traversal me to usi ka use kiya
    // ab agar sorted h to imagine kisi ek point ke liye ya to min uske piche wali node hogi ya aage wali

    // ab hmne kya kiya sabse pehle check kiya parent->left h to usme recursion lga diya ye sochke ki left wale subtree ka min dist ye return kardega
    // ab dekhenge jo ans initially hme max rakha wo leftMin jo aaya left subtree se un dono me konsa min h aur abhi ke liye usi ko min man lenge

    // ab check karenge jo prev h us node se wo agar null nhi h to left subtree check kar liye usse jo ans aaya usko compare karenge jo node h usse prev node ka dist aur left subtree me se min jo aaya wo firse abhi ke liye min man liya...

    // ab hmne agle call pe use karne ke liye prev ko parent kar diya kyoki agle ke liye ab ye prev hoga

    // fir last me right subtree reh gya usme bhi same check karenge

    ///  remember prev ek global var h
    int ans = INT16_MAX;

    if (parent == NULL)
        return INT16_MAX;
    if (parent->left)
    {
        int leftMin = minDistance(parent->left, prev);
        ans = min(ans, leftMin);
    }

    if (prev != NULL)
    {
        ans = min(ans, parent->data - prev->data);
    }

    prev = parent;

    if (parent->right)
    {
        int rightMin = minDistance(parent->right, prev);
        ans = min(ans, rightMin);
    }

    return ans;
}

int main()
{

    vector<int> arr = {13, 8, 1, 5, 10, 16};
    Node *root = buildBST(arr);

    Node *tempPrev = NULL;
    int ans = minDistance(root, tempPrev);

    cout << "Min distance : " << ans;

    return 0;
}