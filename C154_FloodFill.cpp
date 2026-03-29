#include <iostream>
#include <vector>

using namespace std;

void helper(vector<vector<int>> &image, int i, int j, int rows, int cols, int color, int originalColor)
{

    // dekho hmko kya karna ki ek color hoga original ek colour hoga nya new and ya ho skta h 0 ab 0 ka mtlab no color ab poori image array me jo ek index denge uska color new color me change karna h sath sath jo jo bhi neighbours h ya traverse ho skte h ek step me like left right top bootom un sabka color new karna h

    // to simple dfs wala hi rec logic left right top bottom pe chla denge aur agar image se bahar hue ya original color nhi hua to ya to wo new ho chuka ya 0 return whi se ......
    if (i < 0 || i >= rows || j < 0 || j >= cols || image[i][j] != originalColor)
    {
        return;
    }

    image[i][j] = color;

    helper(image, i + 1, j, rows, cols, color, originalColor);
    helper(image, i, j + 1, rows, cols, color, originalColor);
    helper(image, i - 1, j, rows, cols, color, originalColor);
    helper(image, i, j - 1, rows, cols, color, originalColor);
}

vector<vector<int>> findFloddedImage(vector<vector<int>> &image, int newColor, int stR, int stC, int originalColor)
{

    helper(image, stR, stC, image.size(), image[0].size(), newColor, originalColor);
    return image;
}

int main()
{
    vector<vector<int>> image = {
        {1, 1, 1},
        {1, 1, 0},
        {1, 0, 1}};

    vector<vector<int>>
        ans = findFloddedImage(image, 2, 1, 1, 1);

    cout << "New color image :\n";
    for (auto v : ans)
    {
        for (int val : v)
        {
            cout << val << " ";
        }
        cout << endl;
    }
}