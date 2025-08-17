#include <iostream>
#include <vector>
using namespace std;

int main()
{

    // Brute Force...

    vector<int> arr = {1, 3, 4, 6};
    vector<int> ansArr (arr.size());
    int ans;
    for (int i = 0; i < arr.size(); i++)
    {
        ans = 1;
        for (int j = 0; j < arr.size(); j++)
        {
            if (i == j)
            {
                continue;
            }
            else
            {
                ans *= arr[j];
            }
        }
        ansArr[i] = ans;
    }

    for(int val: ansArr){
        cout << val << "\t";
    }



    // Optimized approach with / ....
    int wholeMultiple = 1;
    for(int val: arr){
        wholeMultiple *= val;
    }
    for (int i = 0; i < ansArr.size(); i++){
        ansArr[i] = wholeMultiple / arr[i];
    }
    cout << "\n";
    for(int val: ansArr){
        cout << val << "\t";
    }

    // Optimized Approach without / and time complexity -> O(n) and space complexity -> O(1)....

    // hmne kya kiya ki is par pehle loop me hmne jo ans array h usme jo bhi question array me element se pehle wale element h un sabka product store kar liya lets say suffix.
    // then fir har iteration me second loop ke hmne question array ki help se ek suffix variable me suffix store kiya kar iteration pe par is bar usko save nhi kiya balki uso turant hi ansArray me store kiya.......

    ansArr[0] = 1;
    int suffix = 1;
    for (int i = 1; i < arr.size(); i++){
        ansArr[i] = ansArr[i - 1] * arr[i - 1];
    }
    for (int i = arr.size() - 2; i >= 0; i--){
        suffix *= arr[i+1];
        ansArr[i] = ansArr[i] * suffix;
       
    }
    cout << "\n";
    for(int val: ansArr){
        cout << val << "\t";
    }
    

        return 0;
}