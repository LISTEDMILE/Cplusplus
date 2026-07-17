#include <iostream>
#include <vector>
#include <cstring>
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

int findMaxWidth(Node *parent)
{

    // se hme max width of tree nikalni h
    // to hmne simply level traversal wala logic liya aur har level me uski width nikali aur us hisab se maxWidth ko update karte gye..

    // ab hmne maxW =0 liya q initialize ki jisme pehle hmne push kiya pair of root node and idx 0..

    // ab hmne while loop chlaya jab tak q empty nhi h
    // ab dekho jo ek iteration me queue me h wo ek level ke nodes h to front wale ka index jo pair me idx h aur back wale ka unka difference is the distance or width of that level..

    // us hisab se maxW update kiya.
    // ab hmne us q ke curr size jitna for loop lgaya
    // aur har iteration me usse ek val pop kari aur check kiya agar left exist karta h to push karenge q me uska node and idx ab dekho agar tree ko ek array me store ya imagine kare tohmne padha tha jo parent ka left child hoga dwo us idx se 2*idx +1 pe hoga kyuki binary tree h
    // aur right child 2 *idx +2 pe ...

    // ab aise har element ke liye kiya jo pehle q me the.. aur fir firse ek nya level mil gya ab uske liye width nikalenge agle iteration of while loop me.....

    int maxWidth = 0;
    queue<pair<Node *, int>> q;
    q.push({parent, 0});

    while (!q.empty())
    {
        unsigned long long stIdx = q.front().second;
        unsigned long long enIdx = q.back().second;
        maxWidth = max(maxWidth, int(enIdx - stIdx + 1));

        int currLevelSize = q.size();

        for (int i = 0; i < currLevelSize; i++)
        {
            Node *curr = q.front().first;
            int idx = q.front().second;

            q.pop();
            if (curr->left)
            {
                q.push({curr->left, 2 * idx + 1});
            }
            if (curr->right)
            {
                q.push({curr->right, 2 * idx + 2});
            }
        }
    }

    return maxWidth;
}

int main()
{

    vector<int> arr = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    int idx = -1;
    Node *root = buildTree(arr, idx);

    int maxWidth = findMaxWidth(root);

    cout << "Max width for given tree : " << maxWidth;

    cout << endl
         << endl;
    return 0;
}