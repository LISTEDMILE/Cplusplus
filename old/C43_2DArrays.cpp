#include <iostream>
#include <vector>

using namespace std;

// matrix pass karte hue row no. miss kar skte h par col compulsory hote h...

void search(int a, int mat[4][3], int rows, int cols)
{

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (a == mat[i][j])
            {
                cout << "The element " << a << " found on idx : [" << i << "][" << j << "]\n";
                return;
            }
        }
    }
    cout << "The element " << a << " not found\n";
}

int MaxSum(int mat[4][3], int rows, int cols)
{
    int maxS = INT16_MIN;
    for (int i = 0; i < rows; i++)
    {
        int sum = 0;
        for (int j = 0; j < cols; j++)
        {
            sum += mat[i][j];
        }
        maxS = max(maxS, sum);
    }
    return maxS;
}

int diagonalSum(int mat[4][4], int rows)
{
    int sum = 0;
    for (int i = 0; i < rows; i++)
    {

        for (int j = 0; j < rows; j++)
        {
            if (i == j)
                sum += mat[i][j];
            else if (i + j == rows - 1)
                sum += mat[i][j];
        }
    }
    return sum;
}

int diagonalSumOptimized(int mat[4][4], int rows)
{
    int sum = 0;
    for (int i = 0; i < rows; i++)
    {
        sum += mat[i][i];
        if (rows - i - 1 != i)
            sum += mat[rows - i - 1][i];
    }

    return sum;
}

int main()
{

    int matrix[4][3] = {{2, 5, 2}, {3, 5, 3}, {3, 5, 1}, {3, 5, 2}};
    int rows = 4;
    int cols = 3;

    cout << matrix[2][1] << "\n";

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }

    // input

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << "Row " << i << " col " << j << " : ";
            cin >> matrix[i][j];
        }
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }

    // Linear Search..

    int a;
    cout << "Enter a no. to search : ";
    cin >> a;

    search(a, matrix, rows, cols);

    int maxSum = MaxSum(matrix, rows, cols);
    cout << "The max sum [rows wise]  : " << maxSum << endl;

    // diagonal sum//
    //  .... square matrix....
    int arr[4][4] = {{3, 5, 3, 6}, {3, 6, 3, 4}, {6, 4, 6, 2}, {6, 2, 6, 3}};
    int rowsArr = 4;
    for (int i = 0; i < rowsArr; i++)
    {
        for (int j = 0; j < rowsArr; j++)
        {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
    int sum = diagonalSum(arr, rowsArr);
    cout << "Diagonal sum : " << sum << endl;

    // optimized.. O(n);
    int arrOptimized[4][4] = {{3, 5, 3, 6}, {3, 6, 3, 4}, {6, 4, 6, 2}, {6, 2, 6, 3}};
    int rowsArrOptimized = 4;
    for (int i = 0; i < rowsArrOptimized; i++)
    {
        for (int j = 0; j < rowsArrOptimized; j++)
        {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
    int sumOptimized = diagonalSumOptimized(arr, rowsArrOptimized);
    cout << "Diagonal sum optimized : " << sumOptimized << endl;



    //2D matrix using vectors....
    vector<vector<int>> matt = {{2,3,4},{3,5,4},{5,3,5}};
    // no. of rows = matt.size();
    // no. of cols = matt[i].size();

    cout << "\n\nMatrix using vectors : \n";
    for (int i = 0; i < matt.size(); i++)
    {
        for (int j = 0; j < matt[i].size() ; j++)
        {
            cout << matt[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}