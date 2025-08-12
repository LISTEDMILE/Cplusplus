#include <iostream>
using namespace std;

int main(){
    int age;
    // garbage value as not initialized
    cout << "age = " << age << "\n";

    // cin for input
    cin >> age;
    cout << "age after input = " << age << "\n";
  

    //operators used for arithmetic operations arithmetic operators
    int a = 5, b = 10;
    int sum = a + b;
    cout << "sum = " << sum << "\n";
    int difference= a - b;
    cout << "difference = " << difference << "\n";
    int multiplication = a * b;
    cout << "multiplication = " << multiplication << "\n";
    int division = a / b;
    cout << "division = " << division << "\n";
    int modulus = a % b;
    cout << "modulus = " << modulus << "\n";

    //relational Operator
    //<, > , >= , == ,<=,  !=

    //logical operatos
    // || -> Or 
    // && -> and
    // ! -> not

    //unary operators
    // ++ increment
    // -- decrement

    // assignment operators
    //+=,=,-=

    return 0;

}