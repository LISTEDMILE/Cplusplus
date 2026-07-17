#include <iostream>
#include <vector>

using namespace std;

int findStartIdx(vector<int> gas, vector<int> cost)
{

    // hme kya karna ki do array di hue h jisme gas me har index pe yani har petrol pump pe kitna petrol h wo diya hua..
    // cost ke har index pe ye cost di h ki idx se idx+1 tak jane ke liye kitna petrol lgega...

    // ab hme ye btana ki kha se start kare ki circular array poori travel kar ske.

    // ab sbse pehle check karenge ki possible bhi h simply total gas aur total gas dekhenge agar enough gas h matlab soln h

    // fir ab hm ek var currGas = 0 bnaenge aur start karenge idx 0 se
    // ek ek karke aage bhdenge aur har idx pe currGas me us idx ki gas add karenge aur whi pe check karenge ki ab jo currGas ho gyi h usme agle index pe jana possible h uske liye just check karenge ki currGas less than to nhi h cost[idx] se agar nhi h to possible h uska starting idx hona abhi ke liye
    // to currGas me se jo id idx se idx+1 tak jane ki cost h matlab cost[idx] - karenge aur agli iteration pe jaenge
    // agar less than h to mtlab pichla start possible nhi h aur mind it ki jis idx tak pohoche h wha tak koi bhi nhi ban paega kyoki jab thoda bohot piche se bhi help aai tab bhi nhi ja pare to bina help ke unhi idx se to possible nhi to ab idx +1 se firse check karenge same cheez..

    // aur ha hmne pehle hi find out kar liya ki possible soln exist karta bhi h ya nhi to agar hm forward me check kar rhe to last idx tak jo start h wo hi soln h hme circlular me check karne ki jarurat nhi h.....

    // check if there is any possible answer
    int totalGas = 0;
    int totalCost = 0;
    for (int val : gas)
    {
        totalGas += val;
    }
    for (int val : cost)
    {
        totalCost += val;
    }

    if (totalGas < totalCost)
    {
        return -1;
    }

    // find start....
    int currGas = 0;
    int start = 0;
    for (int i = 0; i < gas.size(); i++)
    {
        currGas += gas[i];
        if (currGas < cost[i])
        {
            start = i + 1;
            currGas = 0;
        }
        else
        {
            currGas -= cost[i];
        }
    }

    return start;
}

int main()
{

    vector<int> gas = {1, 2, 4, 5, 9};
    vector<int> cost = {3, 4, 1, 10, 1};

    int startIdx = findStartIdx(gas, cost);

    if (startIdx == -1)
    {
        cout << "It is not possible with current gas and  cost scenerios.";
    }

    else
    {
        cout << "We can start from idx : " << startIdx << " to cover whole path";
    }
    return 0;
}