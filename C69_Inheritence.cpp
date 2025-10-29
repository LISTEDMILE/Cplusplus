#include <iostream>
#include <string>

using namespace std;

class Parent
{
public:
    Parent()
    {
        cout << "Constructor Parent\n";
    }
    ~Parent()
    {
        cout << "Destructor Parent\n";
    }
};

// here Student class inherited Person.... means it can access methods and properties of Person.
class Child : public Parent
{
public:
    Child() // sequence is first parent constructor => child cons. => child destrotor => parent destructor.
    {
        cout << "Constructor Child\n";
    }
    ~Child()
    {
        cout << "Destroctor Child\n";
    }
};

class Person
{
public:
    string name;
    int age;

    Person(string name, int age)
    {
        this->name = name;
        this->age = age;
    }
};

class Student : public Person
{
public:
    int rollNo;
    // for constructer to include properties of parent class first call parent constructor like this ...
    Student(string name, int age, int rollNo) : Person(name, age)
    {

        this->rollNo = rollNo;
    }
    void getInfo()
    {
        cout << "name : " << name << endl;
        cout << "age : " << age << endl;
        cout << "rollNo : " << rollNo << endl;
    }
};

int main()
{

    // it is concept where properties and functions of base class are passed on to derived class...
    // private properties can never be inherited...
    // protected ko inherit kare kisi bhi derieved class se private se private ban jaegi aur bakiyo me protected hi rhegi..
    // public ko jisse karoge waisi ban jaegi private - private public - public protected - protected...

    Child s1;

    Student("aakash", 20, 29).getInfo();

    return 0;
}