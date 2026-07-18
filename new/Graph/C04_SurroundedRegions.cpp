#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// ===============================================================
// Surrounded Regions
// ===============================================================
//
// We are given a board containing
// 'X' and 'O'.
//
// We have to convert every 'O'
// which is completely surrounded
// by 'X' into 'X'.
//
// Any 'O' connected to the boundary
// can never be surrounded.
//
// Idea:
//
// 1. Push every boundary 'O'
//    into the queue.
//
// 2. Perform BFS and mark every
//    reachable 'O' as visited.
//
// 3. Traverse only the inner cells.
//
//    If a cell is 'O'
//    and was never visited,
//    convert it to 'X'.
//
// Time Complexity : O(N × M)
//
// Space Complexity : O(N × M)
// ===============================================================

void solve(vector<vector<char>> &board)
{

    int n = board.size();
    int m = board[0].size();

    queue<pair<int, int>> q;

    vector<vector<int>> visited(
        n,
        vector<int>(m, 0));

    // -----------------------------------------------------------
    // Push all boundary O's
    // -----------------------------------------------------------

    for (int i = 0; i < n; i++)
    {

        if (board[i][0] == 'O')
        {
            visited[i][0] = 1;
            q.push({i, 0});
        }

        if (board[i][m - 1] == 'O')
        {
            visited[i][m - 1] = 1;
            q.push({i, m - 1});
        }
    }

    for (int i = 0; i < m; i++)
    {

        if (board[0][i] == 'O')
        {
            visited[0][i] = 1;
            q.push({0, i});
        }

        if (board[n - 1][i] == 'O')
        {
            visited[n - 1][i] = 1;
            q.push({n - 1, i});
        }
    }

    // Left Right Up Down

    vector<int> rItr = {0, 0, -1, 1};
    vector<int> cItr = {-1, 1, 0, 0};

    // -----------------------------------------------------------
    // Multi Source BFS
    // -----------------------------------------------------------

    while (!q.empty())
    {

        int r = q.front().first;
        int c = q.front().second;

        q.pop();

        for (int i = 0; i < 4; i++)
        {

            if (r + rItr[i] >= 0 &&
                r + rItr[i] < n &&
                c + cItr[i] >= 0 &&
                c + cItr[i] < m &&
                !visited[r + rItr[i]][c + cItr[i]] &&
                board[r + rItr[i]][c + cItr[i]] == 'O')
            {

                visited[r + rItr[i]][c + cItr[i]] = 1;

                q.push({r + rItr[i], c + cItr[i]});
            }
        }
    }

    // -----------------------------------------------------------
    // Convert unvisited O's
    // -----------------------------------------------------------

    for (int i = 1; i < n - 1; i++)
    {

        for (int j = 1; j < m - 1; j++)
        {

            if (board[i][j] == 'O' &&
                !visited[i][j])
            {

                board[i][j] = 'X';
            }
        }
    }
}

// ===============================================================
// Print Board
// ===============================================================

void printBoard(vector<vector<char>> &board)
{

    for (auto &row : board)
    {

        for (char ch : row)
        {

            cout << ch << " ";
        }

        cout << endl;
    }
}

// ===============================================================
// Main
// ===============================================================

int main()
{

    vector<vector<char>> board =
        {
            {'X', 'X', 'X', 'X'},
            {'X', 'O', 'O', 'X'},
            {'X', 'X', 'O', 'X'},
            {'X', 'O', 'X', 'X'}};

    cout << "Original Board\n\n";

    printBoard(board);

    solve(board);

    cout << "\nAfter Solving\n\n";

    printBoard(board);

    return 0;
}