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

int heightOfTree(Node *root)
{

    if (root == NULL)
    {
        return 0;
    }

    int heightLeftSubTree = heightOfTree(root->left);
    int heightRightSubTree = heightOfTree(root->right);
    return max(heightLeftSubTree, heightRightSubTree) + 1;
}

int diameterOfTree(Node *root)
{

    if (root == NULL)
    {
        return 0;
    }

    int leftDiameter = diameterOfTree(root->left);
    int rightDiameter = diameterOfTree(root->right);
    int rootContainingDia = heightOfTree(root->left) + heightOfTree(root->right);

    return max(leftDiameter, max(rightDiameter, rootContainingDia));
}

int diameterOfTreeOptimal(Node *root, int &ans)
{

    if (root == NULL)
    {
        return 0;
    }

    int heightLeftSubTree = heightOfTree(root->left);
    int heightRightSubTree = heightOfTree(root->right);

    ans = max(ans, heightLeftSubTree + heightRightSubTree);
    return max(heightLeftSubTree, heightRightSubTree) + 1;
}

int main()
{

    // diameter is the distance between any two nodes to hme max distance nikalna h between 2 nodes..

    vector<int> arr = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    int idx = -1;
    Node *root = buildTree(arr, idx);

    // to ab dimag lgaya ki
    // 1. ya to root se hoti hui jae apni deameter
    // 2. ya to left subtree me without root ke diameter ho ulta v ki tarah.
    // 3. ya to right me ho without root.

    // ab hmne kya kiya leftDiameter ko calculate kiya recursion se rightDiamter ko calculate kiya aur calculate kiya wo diameter jo root se jata h through leftHeight and rightHeight of subtree
    // fir return kardiya isme se jo bhi max ho

    // ab dekhte h base case if root == NULL ho jae matlab uska diameter to 0 hi h....

    // time complexity O(n*n)...
    int diameter = diameterOfTree(root);
    cout << "Diameter of tree : " << diameter;

    // optimatll......

    // jo hmara diameter left aur right wala h agar dhyan se soche to wo bhi kisi node ke liye to with root node wala hi deameter h to hm simply diameter ko leftHeight + rightHeight bol skte h us node ke liye aur agar global nikalna h to har node ka nikalke max return kra skte h
    // ab iske liye hmne jo height calculate karne ka recursive fn hota h wo use kiya just ek change ki har iteration pe left and right height ko add karke purane ans se compare karke max ans me store kara rhe h baki sab same....
    int diameterOptimal = 0;
    diameterOfTreeOptimal(root, diameterOptimal);
    cout << "\nDiameter of tree Optimal : " << diameterOptimal;
    return 0;
}