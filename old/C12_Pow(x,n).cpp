#include <iostream>
using namespace std;

int main()
{

    // agar 3 ki power 5 nikalni h to O(n) aati normal loop se but O(log n ) se ho skta h
    // jo exponent h usko binary ki tarah se kar skte h 2 se remainder nikalo fir us hisab se dekho agar one h matlab included h agar 0 matlab included nhi h
    // jo hmara multiplier type ka h here x wo to har iteration me multiple hota rhega par agar 0 h to ans me include nhi hoga  .. isse kya hoga ki ab hme har bar same me multiply karte rho har iteration me fire O(n) se karo nhi hoga ab multiple me multiply hoga like 3 9 27 aise bhadta rhega har iteration me aur jo bhi chahiye wo hm ans me include kar skte h......

    double x = 3;
    long binary = 5;
    double ans = 1;

    while (binary > 0)
    {

        if (binary % 2 == 1)
        {
            ans *= x;
        }
        binary /= 2;
        x *= x;
    }

    cout << ans;

    return 0;
}