#include <iostream>
#include <vector>
#include <climits>
#include <iomanip>

using namespace std;

const int INF = INT_MAX;

// Function to print the matrix
void printMatrix(vector<vector<int>> &mat, int n)
{

    cout << "     ";
    for (int j = 1; j <= n; j++)
        cout << setw(6) << j;
    cout << "\n";

    for (int i = 1; i <= n; i++)
    {

        cout << setw(3) << i << " ";

        for (int j = 1; j <= n; j++)
        {

            if (mat[i][j] == INF)
                cout << setw(6) << "INF";
            else
                cout << setw(6) << mat[i][j];
        }
        cout << "\n";
    }
}

int floydWarshall(int n,
                  int m,
                  int src,
                  int dest,
                  vector<vector<int>> &edges)
{

    vector<vector<int>> adjMat(
        n + 1,
        vector<int>(n + 1, INF));

    // Create adjacency matrix
    for (int i = 0; i < m; i++)
        adjMat[edges[i][0]][edges[i][1]] = edges[i][2];

    for (int i = 1; i <= n; i++)
        adjMat[i][i] = 0;

    cout << "Initial Matrix\n";
    printMatrix(adjMat, n);
    cout << "\n";

    // Floyd Warshall
    for (int k = 1; k <= n; k++)
    {

        cout << "=====================================\n";
        cout << "Using Vertex " << k << " as Intermediate\n";
        cout << "=====================================\n";

        for (int i = 1; i <= n; i++)
        {

            for (int j = 1; j <= n; j++)
            {

                if (adjMat[i][k] == INF || adjMat[k][j] == INF)
                    continue;

                if (adjMat[i][j] > adjMat[i][k] + adjMat[k][j])
                {

                    cout << "Updating (" << i << "," << j << ") : "
                         << (adjMat[i][j] == INF ? -1 : adjMat[i][j])
                         << " -> "
                         << adjMat[i][k] + adjMat[k][j]
                         << "   ("
                         << i << " -> " << k << " -> " << j
                         << ")\n";

                    adjMat[i][j] = adjMat[i][k] + adjMat[k][j];
                }
            }
        }

        cout << "\nMatrix after k = " << k << "\n";
        printMatrix(adjMat, n);
        cout << "\n";
    }

    cout << "=====================================\n";
    cout << "Final Shortest Distance Matrix\n";
    cout << "=====================================\n";
    printMatrix(adjMat, n);
    cout << "\n";

    // Check Negative Cycle
    bool negativeCycle = false;

    for (int i = 1; i <= n; i++)
    {

        if (adjMat[i][i] < 0)
        {
            negativeCycle = true;
            break;
        }
    }

    if (negativeCycle)
    {
        cout << "\nNegative Weight Cycle Detected!\n";
        return -1;
    }

    return adjMat[src][dest] == INF ? (int)1e9 : adjMat[src][dest];
}

int main()
{

    int n = 4;

    vector<vector<int>> edges =
        {
            {1, 2, 3},
            {2, 3, 4},
            {3, 4, 2},
            {1, 4, 15},
            {4, 2, -8}};

    int m = edges.size();

    int src = 1;
    int dest = 4;

    int ans = floydWarshall(n, m, src, dest, edges);

    if (ans != -1)
        cout << "\nShortest Distance from "
             << src << " to "
             << dest << " = "
             << ans << endl;

    cout << "\n\n\n";

    int n2 = 4;

    vector<vector<int>> edges2 =
        {
            {1, 2, 5},
            {1, 4, 10},
            {2, 3, 3},
            {3, 4, 1}};

    int m2 = edges2.size();

    int src2 = 1;
    int dest2 = 4;

    int ans2 = floydWarshall(n2, m2, src2, dest2, edges2);

    if (ans2 != -1)
        cout << "\nShortest Distance from "
             << src2 << " to "
             << dest2 << " = "
             << ans2 << endl;

    return 0;
}