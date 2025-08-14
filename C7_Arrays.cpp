#include <iostream>
using namespace std;

int main(){

    //initialize
    int arr[3];
    int arr1[] = {1, 2, 3};
    int arr2[3] = {1, 2, 3};


    // cannot access like this in C++
    cout << arr << "\n"
         << arr1 << "\n"
         << arr2 << "\n";

    cout << arr1[2] << "\n";
    arr1[2] = 1;
    cout << arr1[2] << "\n";
    // return memory size not no. of elements...
    cout << "size of arr1 : " << sizeof(arr1) << "\n";

    int size = sizeof(arr1) / sizeof(arr1[0]);
    for (int i = 0; i < size; i++){
        cout << arr1[i] << "\t";
    }
    cout << "\n";

    cout << "Enter size of array : ";
    cin >> size;

    int createArray[size];
    for (int i = 0; i < size; i++ ){
        cin >> createArray[i];
    }

    int min = createArray[0];
    int max = createArray[0];
    cout << "Array is : \n";
    for (int i = 0; i < size; i++){
        cout << createArray[i] << "\t";
        if(createArray[i]>max){
            max = createArray[i];
            // also we can use max(createArray[i], max); same with min pre defined functions...
        }
        else if(createArray[i]<min){
            min = createArray[i];
        }
    }

    cout << "\nThe max no. is : " << max << "\nThe min no. is : " << min << "\n";


    // if we pass array as parameter then it is implicitely call by reference it will alter the main array automatically as its starting array is passed not the copy....



    /// Algorithms....

    // Searching.......
     
    // Linear Search..

    int search;
    bool found = false;
    cout << "Enter a no. to search in the array : ";
    cin >> search;
    for (int i = 0; i < size;i++){
        if(createArray[i] == search){
            cout << search << " found at " << " index " << i << " \n";
            found = true;
            break;
        }
        
    }
    if(!found){
        cout << search << " is not in the array. \n";
    }



    // reverse an array
    int temp;
    for (int i = 0; i < size / 2; i++){
        temp = createArray[i];
        createArray[i] = createArray[size -1 - i];
        createArray[size -1 - i] = temp;
    }
    cout << "Reverse of the array is : \n";
    for (int i = 0; i<size ; i++){
        cout << createArray[i] << "\t";
    }
        return 0;
}