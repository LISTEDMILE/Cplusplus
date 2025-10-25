#include <iostream>

using namespace std;

int main()
{
    // endl is for next line
    //  can use \n also (prefer)
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
    // return 1 for true 0 for false
    cout << what << "\n";

    // typeCasting
    // conversion -> small data type se larger me convert compiler khud kar skta h
    char g = 'A';
    int gInt = g;
    cout << "g = " << g << " , gInt = " << gInt << "\n";
    int a = 10;
    double b = a;
    cout << "a = " << a << " , b = " << b << "\n";

    // casting -> larger se smaller explicitely karna padega user ko...
    double c = 20.333;
    int d = c;
    cout << "c = " << c << " , d = " << d << "\n";

    // if two different data type operated larger one will host ans...

    // if we want in some other data type ans we have to type cast anyone
    cout << "With type cast " << (5 / double(2)) << "\n";
    cout << "Without type cast " << (5 / 2) << "\n";

    return 0;
}