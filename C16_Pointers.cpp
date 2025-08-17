#include <iostream>
using namespace std;

void change(int *ptr)
{
    *ptr = 20;
}

void changeByAlias(int &b)
{
    //  here & is not like address it is showing alias means same location means the difference will be on main var....
    b = 30;
}

int main()
{

    // Pointers --> these are the special variables which store the address of other variables....

    // to have address of some variable or data we can use -> addressOf or & symbol...

    int a = 10;
    cout << &a << "\n";

    int *ptr = &a;
    *ptr = *ptr + 1;
    cout << "a : " << a;

    // now pointer to pointer...
    int **ptr2 = &ptr;
    cout << "\n"
         << &a << "\n"
         << ptr << "\n"
         << *ptr2 << "\n";

    // * is also used for dereferencing means to extract value at pointer location...

    // Null pointer..
    int *ptrNull = NULL;

    // pass by reference by pointers
    int h = 10;
    change(&h);
    cout << "\nh : " << h << "\n";

    // pass by reference by alias
    h = 10;
    changeByAlias(h);
    cout << "h by Alias : " << h << "\n";

    // in array the name of array is the pointer to the first element of the array.... But in array this pointer is const means can not change like usual pointers....

    // if we do ++ operation or -- operation on pointer than it will be adding to the pointing location and magnitude will be equal to the data type size like for int 4.... same goes with +1 if int will add 4, +4 +5 etc...operations......

    int arr[] = {1, 2, 3, 4, 5, 5, 6};
    cout << "\n" << *arr << "\t" << *(arr + 1) << "\t" << *(arr + 2) << "\n";

    /// in ptr we can perform - operation it will give no of block of data type between both....

    int *first;
    int *second = first + 2;
    cout << "\nfirst : " << first << "\nsecond : " << second << "\nsecond - first : " << second - first << "\n"; // second - first = no of data type size...
    cout << "first > second : " << (first > second) << "\n";

    // access array using external pointer...
    int *ref = arr;
    cout << "\n" << *ref << "\t" << *(ref + 1) << "\t" << *(ref + 2) << "\n";



    return 0;
}