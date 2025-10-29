#include <iostream>
#include <string>

using namespace std;

class Person
{
public:
    string name;
    int age;
};

class Student : public Person
{
public:
    int rollNo;
    void getInfo()
    {
        cout << "name : " << name << endl;
        cout << "age : " << age << endl;
        cout << "rollNo : " << rollNo << endl;
    }
};

class Teacher : public Person
{
public:
    string subject;
    void getInfo()
    {
        cout << "name : " << name << endl;
        cout << "age : " << age << endl;
        cout << "subject : " << subject << endl;
    }
};

int main()
{

    /// rest all types of inheritence in hybrid inheritence.....

    Student s1;
    s1.name = "aakash";
    s1.age = 20;
    s1.rollNo = 4;
    s1.getInfo();

    Teacher t1;
    t1.name = "rakesh";
    t1.age = 40;
    t1.subject = "Mathematics";
    t1.getInfo();

    return 0;
}