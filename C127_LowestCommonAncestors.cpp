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

void printKthLevel(Node *parent, int level)
{

    if (parent == NULL)
    {

        return;
    }

    if (level == 1)
    {
        cout << parent->data << ' ';
        return;
    }
    printKthLevel(parent->left, level - 1);
    printKthLevel(parent->right, level - 1);
}

Node *LeastCommonAncestor(Node *parent, int p, int q)
{
    if (parent == NULL)
    {
        return NULL;
    }

    if (parent->data == p || parent->data == q)
    {
        return parent;
    }

    Node *leftLCA = LeastCommonAncestor(parent->left, p, q);
    Node *rightLCA = LeastCommonAncestor(parent->right, p, q);

    if (leftLCA != NULL && rightLCA != NULL)
    {
        return parent;
    }
    else if (leftLCA != NULL)
    {
        return leftLCA;
    }
    else
    {
        return rightLCA;
    }
}

int main()
{

    // hme kya karna ki koi bhi 2 node h unse aise konsi lowest node h jo dono ki ancestor h lowest
    // condition is ki is question me solution always exist karega
    // node apni khud ki ancestor bhi hoti h
    // dono nodes same nhi ho skti...

    // ab hmne kya kiya ki dekho agar parent hi null h to null return karenge yani ki abhi tak ek bhi match nhi mila to no lca abhi tak
    // fir condition h ki parent->data agar kisi ek ke equal hua p q me se to to us node ko as lca return kardenge to abhi ke liye wo lca ban chuka h.
    // ab recursion chalu leftLCA me wo lca jo left wale subtree ne lca diya h aur same right me
    // ab man lo dono me hi valid lca de diya yani ki left ne bhi lca de diya aur right ne bhi to matlab yhi wala h common pehla ancestor return kar denge...
    // aur dono aa chuke h required node to ab wo further to aaenge nhi ki ye wala final least common ancestor kisi aur ke sath milke further lca change karde...

    // second case ki leftLCA valid h but is bar right wala nhi to simple abhi tak ka lca leftLCA hi aage return karenge.....

    // same goes with rightLCA.....

    vector<int> arr = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    int idx = -1;
    Node *root = buildTree(arr, idx);

    Node *lca = LeastCommonAncestor(root, 2, 4);

    cout << "Lowest common ancestor : " << lca->data;

    cout << endl
         << endl;
    return 0;
}