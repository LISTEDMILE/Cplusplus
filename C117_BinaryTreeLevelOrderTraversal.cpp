#include <iostream>
#include <vector>
#include <queue>

using namespace std;

///  building tree
// single node....
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
    if (idx >= arr.size()) // if invalid input given like left subtree given but right subtree tak aate me hi arr ke elements khatam fir.....
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

// levelorder traversal..
void levelorderTraverseTree(Node *parent)
{
    // hme kya karna is bar ki level to level top to bottom left to right priint krana
    // hm use karenge queue
    // ek ek karke node pe preorder ki tarah jaenge and print karane ki jagah particular node ka data print karake uske left and right child ko queue me dalenge back se aur fir
    // har iteration me queue ke front se element nikalenge print karenge again uske left aur right subtree push back....

    // time complexity O(n) as the queue is entered and pop only once with each element....

    queue<Node *> q;
    q.push(parent);
    q.push(NULL); // this is only to print level according to levels this works with the if logic inside while loop just to print element in levels....

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
    vector<int> arr = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    int idx = -1;
    Node *root = buildTree(arr, idx);

    cout << "\n\nLevel order Traversal : \n";
    levelorderTraverseTree(root);

    cout << endl;
    return 0;
}