#include <iostream>
using namespace std;

int main()
{
    int age;
    // garbage value as not initialized
    cout << "age = " << age << "\n";

    // cin for input
    cin >> age;
    cout << "age after input = " << age << "\n";

    // operators used for arithmetic operations arithmetic operators
    int a = 5, b = 10;
    int sum = a + b;
    cout << "sum = " << sum << "\n";
    int difference = a - b;
    cout << "difference = " << difference << "\n";
    int multiplication = a * b;
    cout << "multiplication = " << multiplication << "\n";
    int division = a / b;
    cout << "division = " << division << "\n";
    int modulus = a % b;
    cout << "modulus = " << modulus << "\n";

    // relational Operator
    //<, > , >= , == ,<=,  !=

    // logical operatos
    //  || -> Or
    //  && -> and
    //  ! -> not

    // unary operators
    //  ++ increment
    //  -- decrement

    // assignment operators
    //+=,=,-=

    // bitwise operator
    //  & -> and
    //  | -> or
    //  ^ -> exor
    //  << -> left shift
    //  >> -> right shift

    // // wap to check if a no. is in power of 2 (no loops)..
    // cout << "Enter a no. : " << "\n";
    // cin >> a;
    // cout << (a << 1);
    // if((a<<1) == 0){

    //     cout << a << " is in power of 2 \n";
    // }
    // else {
    //     cout << a << " is not in power of 2 \n";
    // }

    return 0;
}