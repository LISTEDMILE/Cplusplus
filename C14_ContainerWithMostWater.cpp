#include <iostream>
#include <vector>
using namespace std;

int main()
{

    // we have an array jisme each element ko hm ek wall ki tarah consider karenge jiski height hogi uske magnitude ke equal and do wall ke beech ka distance hoga do index ke beech ka distance..
    // jisse hme area pta chlega taki hm max space calculate kar ske....

    // Brute Force Approach....

    vector<int> container = {3, 1, 5, 6, 2, 4};

    int maxVol = 0;
    for (int i = 0; i < container.size(); i++)
    {
        for (int j = i + 1; j < container.size(); j++)
        {
            maxVol = max(maxVol, ((j - i) * (min(container[i], container[j]))));
        }
    }

    cout << "Max capacity : " << maxVol;

    // Optimized Approach.....

    // kya karenge ki sbse pehle 2 pointer type se first and last element ko point karenge unki capacity nikalenge fir agar left wala chota h to usko ek aage bhda denge aur agar right wala chota h to usko peeche le jaenge aisa tab tak karenge jab tak dono pointer ya to match na ho jae yha left wala right se right me aa jae har iteration me capacity nikalenge jo badi hogi assign ho jaegi.....

    maxVol = 0;
    int lp = 0;
    int rp = container.size() - 1;
    while (lp < rp)
    {
        maxVol = max(maxVol, ((min(container[rp], container[lp])) * (rp - lp)));
        lp > rp ? rp-- : lp++;
    }

    cout << "\nMax Capacity by 2 Pointer Approach : " << maxVol;

    return 0;
}