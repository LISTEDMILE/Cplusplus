#include <iostream>
using namespace std;


void printHello(){
    cout << "Hello World \n";
}
int Return(){
    cout << "Return \n";
    return 2;
}

int add (int a , int b){
    return a + b;
}

int fact (int a ){
    int b = 1;
    for (int i = 1; i <= a; i++){
        b *= i;
    }
    return b;
}

int main(){

    // function define kiya uper yha call kar liya...
    printHello();
    int a = Return();
    cout << a << "\n";

    cout << Return() << "\n";

    // parameters which i send with call and the var used by function is arguments function have return type....
    cout << add(10, 20) << "\n";

    cout << fact(5) << "\n";

    // functions are stred in call stack a stack jo bhi execute ya call hota h wo tos pe hota h fir completion pe apna flow de deta h...

    return 0;
}