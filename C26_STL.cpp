#include <iostream>
#include <vector>
using namespace std;

int main()
{

    vector<int> arr1;
    vector<int> arr2 = {1, 2};
    vector<int> arr3(10, 2);
    vector<int> arr4(arr3);

    cout << arr1.size() << "\t" << arr2.size() << "\t" << arr3.size() << "\t" << arr4.size() << "\n";

    for (int val : arr2)
    {
        cout << val << " ";
    }
    cout << "\n";

    for (int val : arr3)
    {
        cout << val << " ";
    }
    cout << "\n";

    for (int val : arr4)
    {
        cout << val << " ";
    }
    cout << "\n";

    arr2.push_back(4);
    cout << "Arr2 : ";
    for (int val : arr2)
    {
        cout << val << " ";
    }
    cout << "\nSize of Arr2 : " << arr2.size();
    cout << "\nCapacity of Arr2 : " << arr2.capacity();

    arr2.pop_back();
    cout << "\nArr2 after pop : ";
    for (int val : arr2)
    {
        cout << val << " ";
    }

    cout << "\nThe element at index 0 : " << arr2.at(0);

    cout << "\nThe element at front : " << arr2.front();

    cout << "\nThe element at back : " << arr2.back();

    vector<int> arr5 = {1, 2, 3, 4, 5, 6};
    cout << "\nArr5 : ";
    for(int val:arr5){
        cout << val << " ";
    }

    //erase one element remove one element..
    arr5.erase(arr5.begin());

    cout << "\nArr5 after removing first : ";
    for(int val:arr5){
        cout << val << " ";
    }

    // erase a seq by entering start and end of deletion....
    arr5.erase(arr5.begin() + 1, arr5.begin() + 3);
    cout << "\nArr5 after removing 2nd and 3rd : ";
    for(int val:arr5){
        cout << val << " ";
    }

    arr5.insert(arr5.begin() + 2, 100);
    cout << "\nArr5 after insertion 100 : ";
     for(int val:arr5){
        cout << val << " ";
    }

    cout << "\nSize(Arr5) : " << arr5.size() << "\nCapacity(Arr5) : " << arr5.capacity();

    arr5.clear();
     cout << "\nArr5 clear : ";
     for(int val:arr5){
        cout << val << " ";
    }

    cout << "\nArr5 Is Empty : " << arr5.empty();

    return 0;
}