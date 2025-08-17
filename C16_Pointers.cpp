#include <iostream>
using namespace std;

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
    cout << "\n" << &a << "\n" << ptr << "\n" << *ptr2 << "\n";

    // * is also used for dereferencing means to extract value at pointer location...

    // Null pointer..
    int *ptrNull = NULL;

    return 0;
}