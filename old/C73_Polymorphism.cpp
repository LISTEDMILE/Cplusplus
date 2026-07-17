#include <iostream>

using namespace std;

class Student
{
public:
    string name;

    // Constructor overloading..
    Student()
    {
        cout << "non - parameterized constructor\n";
    }

    Student(string name)
    {
        this->name = name;
        cout << "parameterized constructor\n";
    }

    // function overloading...
    void getInfo()
    {
        cout << "Hi\n";
    }

    void getInfo(int a)
    {
        cout << "int : " << a << endl;
    }

    void getInfo(char a)
    {
        cout << "Char : " << a << endl;
    }

    virtual void hello()
    {
        cout << "Vertual Parent\n";
    }
};

class SectionA : public Student
{
public:
    int rollNo;
    void getInfo()
    {
        cout << "Function Overriding\n";
    }
    void hello()
    {
        cout << "Vertual Child\n";
    }
};

int main()
{

    // when the same method or function behave differently..

    // Types -
    // 1. Compile Time Polymorphism => Constructor Overloading, Function Overloading , Operator Overloading => when our function methods or constructors are multiple with same name but the no. of type of parameters should vary so which methods or constructor to execute will be decided by the type fo no. of arguments we give at creation of object or calling of function....

    // 2. Run Time Polymorphism =>
    // function overriding => when parent and child have the same function with different implimentation.....parent class ka function overridden ho jata h.....
    // vertual function => similar to func overriding these are expected in parent class to be implemented by child class again...

    Student s1;
    Student s2("This");

    s2.getInfo();
    s2.getInfo(2);
    s2.getInfo('t');

    SectionA sec1;
    sec1.getInfo();

    s2.hello();
    sec1.hello();
    return 0;
}