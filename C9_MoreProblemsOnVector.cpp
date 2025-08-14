#include <iostream>
using namespace std;

int main(){

    //P 1.1


    // a subarray is a part of array which is continuos
    // like in array [1,2,3,4] -> [1],[2]....,[1,2],[2,3]....[1,2,3],[2,3,4]....[1,2,3,4]

    // at first print all subarrays...
    int n = 5;
    int arr[n] = {1, -2, -3, 4, 5};

    for (int i = 0; i < n;i++){
        for (int j = i; j < n;j++){
            cout << "  [ ";
            for (int k = i; k <= j;k++){
                cout << arr[k] << " ";
            }
            cout << "]  ";
        }
        cout << "\n";
    }


    //P 1.2
    // now print the subarray whose sum is max...
    // brute force approach means like normal tracking like we did finding max of array...
    int maxSum = INT8_MIN;
    int currentSum;
    for (int i = 0; i < n; i++){
      currentSum = 0;
        for (int j = i; j < n; j++){
            currentSum += arr[j];
            if(currentSum>maxSum){
                maxSum = currentSum;
            }
        }
    }

    cout << "\nThe maxSum subArray is : " << maxSum;


    // More Optimized ==>  Kadane's Algorithm....
    // see there is a simple funda ki bhai pehle to currSum ko bhdate rho aur maxSum se compare karte chlo aur swaping but ek aur step h ki dekho agar +ve value aai to sahir h ki wo badhti hi rhegi par agar -ve value aai aur usne kuch less kar diya hmara sum to thik h kuch to contribute hi karega but but but agar wo kisi tarah -ve me pohocha to aage chalke chahe no. positive ho jae but ye -ve to usko ghata hi rha h matlab agar hm us -ve ko 0 bnade to wo least nuksan karega matlab agar koi no. ghata rha h to usko just chod denge......

    maxSum = INT8_MIN;
    currentSum = 0;
    for (int i = 0; i < n;i++ ){
        currentSum += arr[i];
       maxSum = max(currentSum, maxSum);
       if(currentSum<0){
           currentSum = 0;
       }
    }

    cout << "\nThe max sum of subarray by Kadane's Algorithm : " << maxSum;

    return 0;
}