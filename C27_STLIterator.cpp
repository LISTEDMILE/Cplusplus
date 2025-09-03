#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

int main()
{

    vector<int> arr = {1, 2, 4, 5, 6, 7};

    // this below syntax show how to initialize an iterator it means to create an iterator for vector, and vector of type int and the iterator is itr the name i given and this doesn't point anywhere for now....
    vector<int>::iterator itr;

    cout << "\nIteration : ";
    // now itr start pointing ro arr.begin() and this goes on and the iterator value increased means pointing next and next at last if reached end terminate ..
    // to access value use * just like pointer......
    for (itr = arr.begin(); itr != arr.end(); itr++)
    {
        cout << *(itr) << " ";
    }

    cout << "\nReverse Iteration : ";
    // same for reverse iteration....
    vector<int>::reverse_iterator ritr;
    for (ritr = arr.rbegin(); ritr != arr.rend(); ritr++)
    {
        cout << *(ritr) << " ";
    }

    cout << "\nUsing Directly in loop : ";
    // we can use it directly in for loop like this....
    for (vector<int>::iterator itrDirect = arr.begin(); itrDirect != arr.end(); itrDirect++)
    {
        cout << *(itrDirect) << " ";
    }

    cout << "\nUsing auto keyword : ";
    // For performing it C++ provide a shortcut in place of this line write auto ....
    for (auto itrr = arr.begin(); itrr != arr.end(); itrr++)
    {
        cout << *(itrr) << " ";
    }
    return 0;
}