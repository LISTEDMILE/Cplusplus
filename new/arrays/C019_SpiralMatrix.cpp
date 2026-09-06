#include <bits/stdc++.h>
using namespace std;

// 1. GENERATE SPIRAL MATRIX
// Time: O(n²)
// Space: O(n²)

vector<vector<int>> generateMatrix(int n)
{
    vector<vector<int>> mat(n, vector<int>(n));

    int rowS = 0;
    int rowE = n - 1;
    int colS = 0;
    int colE = n - 1;

    int i = 0;

    while (rowS <= rowE && colS <= colE)
    {
        // Top
        for (int j = colS; j <= colE; j++)
            mat[rowS][j] = ++i;

        // Right
        for (int j = rowS + 1; j <= rowE; j++)
            mat[j][colE] = ++i;

        // Bottom
        for (int j = colE - 1; j >= colS; j--)
            mat[rowE][j] = ++i;

        // Left
        for (int j = rowE - 1; j > rowS; j--)
            mat[j][colS] = ++i;

        rowS++;
        colS++;
        rowE--;
        colE--;
    }

    return mat;
}

// 2. SPIRAL MATRIX
// Print all 4 sides and update pointers
// Time: O(n²)
// Space: O(1) excluding answer

vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();

    vector<int> ans;

    int rowS = 0;
    int rowE = n - 1;
    int colS = 0;
    int colE = m - 1;

    while (rowS <= rowE && colS <= colE)
    {
        // Top
        for (int j = colS; j <= colE; j++)
            ans.push_back(matrix[rowS][j]);

        rowS++;

        // Right
        for (int i = rowS; i <= rowE; i++)
            ans.push_back(matrix[i][colE]);

        colE--;

        // Bottom
        if (rowS <= rowE)
        {
            for (int j = colE; j >= colS; j--)
                ans.push_back(matrix[rowE][j]);

            rowE--;
        }

        // Left
        if (colS <= colE)
        {
            for (int i = rowE; i >= rowS; i--)
                ans.push_back(matrix[i][colS]);

            colS++;
        }
    }

    return ans;
}

void printMatrix(vector<vector<int>> &mat)
{
    for (auto &row : mat)
    {
        for (int val : row)
            cout << val << " ";

        cout << endl;
    }
}

void printArray(vector<int> &ans)
{
    for (int val : ans)
        cout << val << " ";

    cout << endl;
}

int main()
{
    // Generate Spiral Matrix

    int n = 3;

    vector<vector<int>> generated = generateMatrix(n);

    cout << "Generated Matrix:" << endl;
    printMatrix(generated);

    // Spiral Order of Existing Matrix

    vector<vector<int>> matrix =
        {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}};

    vector<int> ans = spiralOrder(matrix);

    cout << "\nSpiral Order:" << endl;
    printArray(ans);

    return 0;
}
