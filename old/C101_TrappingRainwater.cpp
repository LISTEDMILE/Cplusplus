#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int MaxOfHeights(vector<int> arr, int i)
{
    int leftMax = 0;
    int rightMax = 0;
    for (int j = 0; j <= i; j++)
    {

        leftMax = max(leftMax, arr[j]);
    }
    for (int j = i; j < arr.size(); j++)
    {

        rightMax = max(rightMax, arr[j]);
    }
    return min(leftMax, rightMax);
}

int AreaBruteForce(vector<int> arr)
{

    // hme kya karna ki every elments ko imagine as bar of bar chart ab uper se pani bharenge to kitna pani contain hoga ..

    // hmne kya kiya pehle aur last bar se to pani bahar ki side girega hi girega to hmne unko chodke sabpe sabse pehle left me sabse bda kon aur fir right me sabse bda kon wo nikala unme se bhi jo chota wala h utna hieght ka pani aa skta us particular bar ke uper ..
    // to hmne us capacity me se bar ki height minus kardi jisse us bar ke uper kitna pani aa skta pata chal gya..

    int ans = 0;
    for (int i = 1; i < arr.size() - 1; i++)
    {
        int height = MaxOfHeights(arr, i) - arr[i];

        ans = ans + height;
    }
    return ans;
}

int AreaBetter(vector<int> arr)
{

    // isme kya kiya ki pehle har element ke liye rmax aur lmax vector bnaliye max ye do array har element ke liye right max aur left max store karengi
    // uske bad same min of max(r,l) choose karke usme se length of particular bar minus ki aur ans me add karte gye area aa hya....

    int n = arr.size();
    int ans = 0;
    vector<int> lmax(n, 0);
    vector<int> rmax(n, 0);
    lmax[0] = arr[0];
    rmax[n - 1] = arr[n - 1];
    for (int i = 1; i < n; i++)
    {
        lmax[i] = max(lmax[i - 1], arr[i]);
    }
    for (int i = 0; i < n - 1; i++)
    {
        rmax[i] = max(rmax[i - 1], arr[i]);
    }

    for (int i = 0; i < n; i++)
    {
        ans += min(lmax[i], rmax[i]) - arr[i];
    }

    return ans;
}

int AreaOptimalTwoPointers(vector<int> arr)
{

    // isme kya kiya ki rmax and lmax 2 var bnae ab ham use karenge 2 pointers l and r
    // loop tab tak chlega jab tak l chota h r se kyoki l right ki taraf bhdega and r left ki taraf..
    // har iteration me lmax nikalenge max(lmax, arr[l ya r])  fir check karenge agar lmax chota h matlab deciding factor to lmax hi h to ans me lmax - arr[l] minus karke add karenge fir l++ karenge but abhi bhi lmax same h agar change hona hoga to agle iteration me hoga ..
    // agar rmax bda h to r-- hoga...

    int n = arr.size();
    int rmax = arr[n - 1];
    int lmax = arr[0];
    int l = 0;
    int r = n - 1;
    int ans = 0;
    while (l < r)
    {
        lmax = max(lmax, arr[l]);
        rmax = max(rmax, arr[r]);
        if (lmax < rmax)
        {
            ans += lmax - arr[l];
            l++;
        }
        else
        {
            ans += rmax - arr[r];
            r--;
        }
    }
    return ans;
}

int main()
{
    vector<int> arr = {3, 4, 2, 6, 2, 6};
    int areaBruteForce = AreaBruteForce(arr);
    cout << "Max water (Brute Force) : " << areaBruteForce << " units\n";

    int areaBetter = AreaBetter(arr);
    cout << "Max water (Better) : " << areaBetter << " units\n";

    int areaOptimalTwoPointers = AreaOptimalTwoPointers(arr);
    cout << "Max water (Optimal Two Pointers) : " << areaOptimalTwoPointers << " units\n";
    return 0;
}