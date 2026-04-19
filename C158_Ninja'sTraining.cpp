#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int solveNinja(vector<vector<int>> &points, int day, int tasks, int lastTask) // t -> O(tasks^n) s -> O(1)
{
    if (day == 0)
    {
        int maxPoints = 0;
        for (int task = 0; task < tasks; task++)
        {
            if (task != lastTask)
                maxPoints = max(maxPoints, points[0][task]);
        }
        return maxPoints;
    }

    int best = 0;

    for (int task = 0; task < tasks; task++)
    {
        if (task != lastTask)
        {
            int current = points[day][task] +
                          solveNinja(points, day - 1, tasks, task);

            best = max(best, current);
        }
    }

    return best;
}

int helperOptimal(vector<vector<int>> &points, int day, int tasks, int lastTaskIdx, vector<vector<int>> &dp)
{ // t -> O(n*lastTasksvalues*tasks) s-> O(n*lastTaskPossibilities) + O(n)
    if (day == 0)
    {
        int maxPoints = 0;
        for (int task = 0; task < tasks; task++)
        {
            if (task != lastTaskIdx)
                maxPoints = max(maxPoints, points[0][task]);
        }
        return maxPoints;
    }

    if (dp[day][lastTaskIdx] != -1)
        return dp[day][lastTaskIdx];

    int best = 0;

    for (int task = 0; task < tasks; task++)
    {
        if (task != lastTaskIdx)
        {
            int current = points[day][task] +
                          helperOptimal(points, day - 1, tasks, task, dp);

            best = max(best, current);
        }
    }

    return dp[day][lastTaskIdx] = best;
}

int solveNinjaOptimal(vector<vector<int>> &points)
{
    vector<vector<int>> dp(points.size(), vector<int>(points[0].size() + 1, -1));
    return helperOptimal(points, points.size() - 1, points[0].size(), points[0].size(), dp);
}

int main()
{
    vector<vector<int>> points = {
        {1, 45, 4},
        {56, 2, 1},
        {3, 3, 5},
        {23, 45, 23},
        {3, 5, 6}};

    cout << "Recursive max output = "
         << solveNinja(points, points.size() - 1, points[0].size(), -1);

    cout << "\nMemoization = " << solveNinjaOptimal(points);

    return 0;
}