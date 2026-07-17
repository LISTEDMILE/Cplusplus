#include <iostream>
#include <vector>
using namespace std;

vector<int> findTargetSumPair(vector<int> nums, int target)
{
    vector<int> sum;
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            if (nums[i] + nums[j] == target)
            {
                sum.push_back(i);
                sum.push_back(j);
                return sum;
            }
        }
    }
    return sum;
}

vector<int> findTargetSumPairOp(vector<int> nums, int target)
{
    vector<int> sum;
    int i = 0;
    int j = nums.size() - 1;
    while (i < j)
    {
        if (nums[i] + nums[j] == target)
        {
            sum.push_back(i);
            sum.push_back(j);
            return sum;
        }
        else if (nums[i] + nums[j] > target)
        {
            j--;
        }
        else
        {
            i++;
        }
    }
}
int main()
{

    // find the pair with perfect sum equals to target..
    vector<int> vec = {1, 2, 4, 5, 6};
    int target = 9;

    vector<int> ans = findTargetSumPair(vec, target);
    cout << ans[0] << " , " << ans[1] << "\n";

    /// Optimization...
    vector<int> sumOp = findTargetSumPairOp(vec, target);
    cout << ans[0] << " , " << ans[1] << "\n";

    return 0;
}