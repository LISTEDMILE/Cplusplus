#include <iostream>
#include <vector>

using namespace std;

// 0/1 Knapsack Problem
//
// Given:
// weights[] -> weight of each item
// values[]  -> value of each item
// W         -> maximum capacity of the knapsack
//
// Each item can be picked at most once.
//
// Goal:
// Maximize the total value without exceeding the capacity.

// ---------------------------------------------------------------
// Recursion
// ---------------------------------------------------------------

int knapsackRecursion(vector<int> &weights,
                      vector<int> &values,
                      int capacity, int n)
{

    if (n == 0)
    {
        if (weights[0] <= capacity)
            return values[0];
        return 0;
    }

    int notTake = knapsackRecursion(weights, values, capacity, n - 1);
    int take = INT16_MIN;

    if (weights[n] <= capacity)
        take = values[n] + knapsackRecursion(weights, values, capacity - weights[n], n - 1);

    return max(notTake, take);
}

// ---------------------------------------------------------------
// Memoization
// ---------------------------------------------------------------

int knapsackMemoization(vector<int> &weights,
                        vector<int> &values,
                        int capacity, int n, vector<vector<int>> &dp)
{

    if (n == 0)
    {
        if (weights[0] <= capacity)
            return values[0];
        return 0;
    }

    if (dp[n][capacity] != -1)
        return dp[n][capacity];
    int notTake = knapsackMemoization(weights, values, capacity, n - 1, dp);
    int take = INT16_MIN;

    if (weights[n] <= capacity)
        take = values[n] + knapsackMemoization(weights, values, capacity - weights[n], n - 1, dp);

    return dp[n][capacity] = max(notTake, take);
}

// ---------------------------------------------------------------
// Tabulation
// ---------------------------------------------------------------

int knapsackOptimalTabulation(vector<int> &weights,
                              vector<int> &values,
                              int capacity)
{
    int n = weights.size();
    vector<vector<int>> dp(n, vector<int>(capacity + 1, 0));

    // for (int i = 0; i < n; i++)
    // {
    //     dp[i][0] = 0;
    // }

    for (int i = weights[0]; i <= capacity; i++)
        dp[0][i] = values[0];

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= capacity; j++)
        {

            int notTake = dp[i - 1][j];
            int take = INT16_MIN;
            if (weights[i] <= j)
                take = dp[i - 1][j - weights[i]] + values[i];

            dp[i][j] = max(take, notTake);
        }
    }

    return dp[n - 1][capacity];
}

// ---------------------------------------------------------------
// Space Optimization
//
// Only previous row is required.
// ---------------------------------------------------------------

int knapsackMostOptimized(vector<int> &weights,
                          vector<int> &values,
                          int capacity)
{

    int n = weights.size();
    vector<int> dp(capacity + 1, 0);

    // dp[0] = 0;

    for (int i = weights[0]; i <= capacity; i++)
        dp[i] = values[0];

    for (int i = 1; i < n; i++)
    {
        vector<int> temp(capacity + 1, 0);
        for (int j = 1; j <= capacity; j++)
        {

            int notTake = dp[j];
            int take = INT16_MIN;
            if (weights[i] <= j)
                take = dp[j - weights[i]] + values[i];

            temp[j] = max(take, notTake);
        }
        dp = temp;
    }

    return dp[capacity];
}

int knapsackMostOptimizedEvenMore(vector<int> &weights,
                                  vector<int> &values,
                                  int capacity)
{ // if our dp only uses idx lesser than jo hm dhoond rhe to alag se temp lene ki kya jarurat usi me updte karenge.. to ulta ierate karenge...

    int n = weights.size();
    vector<int> dp(capacity + 1, 0);

    // dp[0] = 0;

    for (int i = weights[0]; i <= capacity; i++)
        dp[i] = values[0];

    for (int i = 1; i < n; i++)
    {

        for (int j = capacity; j >= 1; j--)
        {

            int notTake = dp[j];
            int take = INT16_MIN;
            if (weights[i] <= j)
                take = dp[j - weights[i]] + values[i];

            dp[j] = max(take, notTake);
        }
    }

    return dp[capacity];
}

int main()
{
    vector<int> weights = {1, 2, 4, 5};
    vector<int> values = {5, 4, 8, 6};

    int capacity = 5;
    int n = weights.size();

    cout << "Maximum Value (Recursion) : "
         << knapsackRecursion(weights,
                              values,
                              capacity, n - 1);

    vector<vector<int>> dp(n, vector<int>(capacity + 1, -1));

    cout << "\nMaximum Value (Memoization) : "
         << knapsackMemoization(weights,
                                values,
                                capacity, n - 1, dp);

    cout << "\nMaximum Value (Tabulation) : "
         << knapsackOptimalTabulation(weights,
                                      values,
                                      capacity);

    cout << "\nMaximum Value (Most Optimized) : "
         << knapsackMostOptimized(weights,
                                  values,
                                  capacity);

    cout << "\nMaximum Value (Most Optimized Even More) : "
         << knapsackMostOptimizedEvenMore(weights,
                                          values,
                                          capacity);

    return 0;
}