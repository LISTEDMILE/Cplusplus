#include <iostream>

using namespace std;

class Shape
{
    virtual void draw() = 0; // pure vertual function ( = 0 ; se bangya pure virtual) => automatically make class abstract
};

// class Circle implementing Shape
class Circle : public Shape
{
public:
    void draw()
    {
        cout << "drawing a circle\n";
    }
};

int main()
{
    // Abstraction => Hiding unneccessary and private data and showing only important and authorized things...
    // It is dont by access modifiers public,private,protected and ===
    // abstract class.....

    // Abstract class => it defines the blue print and structure of other class which will be derived from it.
    // they are implemented from other classes...
    // typically used to define an interface from derived classes.

    Circle c1;
    c1.draw();
    return 0;
}