#include <iostream>

using namespace std;

int main(){
    //endl is for next line 
    // can use \n also (prefer)
    cout << "Cout" << endl;
    cout << "is for printing \n";

    int age = 25;
    cout << age << "\n";

    // sizeof() for size
    cout << sizeof(age) << "\n";

    char firs = 't';
    cout << firs << "\n";

    // f is written other wise considered double
    float PI = 3.14f;
    cout << PI << "\n";

    bool what = true;
    //return 1 for true 0 for false
    cout << what << "\n";
   
    return 0;
}