#include <iostream>
#include <vector>
using namespace std;

int main()
{

    // hme yha stocks buy aur sell karne h to yha pe array me stocks ke price h to pehle hm khareedenge fir aage chalke bhech denge jaise 1 me kharrede to 7 me nhi bech skte aage jake bechna hoga
    // chalte chalte jo min price me milega wo khareed lenge matlab jaise jaise aage bhadenge dekhte chalenge best min price konsa h fir har step pe us min price ke hisab se hi ye dekhenge ki ab ke price me max profit aara h ya pehle wala better tha ....

    vector<int> stocks = {7, 1, 5, 3, 6, 4};
    int maxProfit = 0;
    int bestBuy = stocks[0];

    for (int val : stocks)
    {
        if (val > bestBuy)
        {
            maxProfit = max(maxProfit, val - bestBuy);
        }
        bestBuy = min(bestBuy, val);
    }

    cout << "Max profit : " << maxProfit;

    return 0;
}