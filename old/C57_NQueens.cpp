#include <iostream>
#include <vector>

using namespace std;

bool isSafe(vector<vector<int>> &board, int row, int col, int n)
{
    for (int i = 0; i <= row; i++)
    {
        if (board[i][col] == 'Q')
            return false;
    }

    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j] == 'Q')
            return false;
    }

    for (int i = row, j = col; i >= 0 && j < n; i--, j++)
    {
        if (board[i][j] == 'Q')
            return false;
    }

    return true;
}

void nQueens(vector<vector<int>> &board, int row, int n, vector<vector<vector<int>>> &ans)
{
    if (row == n)
    {
        ans.push_back(board);

        return;
    }
    for (int j = 0; j < n; j++)
    {
        if (isSafe(board, row, j, n))
        {
            // assigning queens to cells
            board[row][j] = 1;
            // every time calling for each row.
            nQueens(board, row + 1, n, ans);
            // in case of failure agar return nhi hua safe position nhi mili to wapis aake us queen ko wha se htaya taki next iteration me doosre col me add karde....
            board[row][j] = 0;
        }
    }
}

int main()
{

    int n = 4;
    vector<vector<int>> board(n, vector<int>(n, 0));
    vector<vector<vector<int>>> ans;
    nQueens(board, 0, n, ans);

    for (auto val : ans)
    {
        for (auto val1 : val)
        {

            cout << " | ";
            for (int val2 : val1)
            {
                cout << val2 << " ";
            }
            cout << "|\n";
        }

        cout << "\n";
    }

    return 0;
}