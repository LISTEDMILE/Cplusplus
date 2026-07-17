#include <iostream>
#include <vector>

using namespace std;

vector<int> spiralMatrix(vector<vector<int>> arr)
{
    int srow = 0, scol = 0, erow = arr.size() - 1, ecol = arr[0].size() - 1;
    vector<int> ans;
    // spiral me traverse karenge..
    while (srow <= erow && scol <= ecol)
    {
        /// pehle top left to right gye..
        for (int j = scol; j <= ecol; j++)
        {
            ans.push_back(arr[srow][j]);
        }
        // right top to bottom..
        for (int i = srow + 1; i <= erow; i++)
        {
            ans.push_back(arr[i][ecol]);
        }
        // bottom right to left..
        for (int j = ecol - 1; j >= scol; j--)
        {
            if (srow == erow)
            {
                break;
            }
            ans.push_back(arr[erow][j]);
        }
        // left bottom to top..
        for (int i = erow - 1; i > srow; i--)
        {
            if (scol == ecol)
            {
                break;
            }
            ans.push_back(arr[i][scol]);
        }

        srow++;
        erow--;
        scol++;
        ecol--;
    }

    return ans;
}

int main()
{

    vector<vector<int>> arr = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};

    vector<int> ans = spiralMatrix(arr);
    cout << "Previous matrix :\n";
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[0].size(); j++)
        {
            cout << arr[i][j] << "  ";
        }
        cout << endl;
    }
    for (int val : ans)
    {
        cout << val << "\t";
    }
    return 0;
}