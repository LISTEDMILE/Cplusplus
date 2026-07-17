#include <iostream>
#include <stack>
#include <vector>

using namespace std;

vector<int> findRightNearest(vector<int> arr)
{
    vector<int> ans(arr.size(), 0);
    stack<int> s;

    for (int i = arr.size() - 1; i >= 0; i--)
    {
        while (s.size() > 0 && arr[s.top()] >= arr[i])
        {
            s.pop();
        }

        if (s.empty())
        {
            // small change if sare hi bde h to max index se ek jyada taki last index tak sare add hoske....
            ans[i] = arr.size();
        }
        else
        {
            ans[i] = s.top();
        }
        s.push(i);
    }

    return ans;
}

vector<int> findLeftNearest(vector<int> arr)
{
    vector<int> ans(arr.size(), 0);
    stack<int> s;

    for (int i = 0; i < arr.size(); i++)
    {
        while (s.size() > 0 && arr[s.top()] >= arr[i])
        {
            s.pop();
        }

        if (s.empty())
        {
            // small change as we want area to if sare hi bde h to min index se ek kam taki sare elements add hoske..
            ans[i] = -1;
        }
        else
        {
            ans[i] = s.top();
        }
        s.push(i);
    }
    return ans;
}

int largestRectangle(vector<int> heights)
{

    // hme kya karna h ki hme find karna max area wala rectangle ab uske liye
    vector<int> rightNearestSmaller = findRightNearest(heights);
    vector<int> leftNearestSmaller = findLeftNearest(heights);

    int ans = 0;
    for (int i = 0; i < heights.size(); i++)
    {
        int width = rightNearestSmaller[i] - leftNearestSmaller[i] - 1;
        int currentArea = heights[i] * width;
        ans = max(currentArea, ans);
    }
    return ans;
}

int main()
{

    vector<int> arr = {3, 4, 2, 5, 6};
    int maxArea = largestRectangle(arr);
    cout << "Max are is : " << maxArea;
    return 0;
}