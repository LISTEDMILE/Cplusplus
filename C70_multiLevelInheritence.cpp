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
};

class GradStudents : public Student
{
public:
    string researchArea;
    void getInfo()
    {
        cout << "name : " << name << endl;
        cout << "age : " << age << endl;
        cout << "rollNo : " << rollNo << endl;
        cout << "reserachArea : " << researchArea << endl;
    }
};

int main()
{

    GradStudents s1;
    s1.name = "aakash";
    s1.age = 20;
    s1.rollNo = 4;
    s1.researchArea = "CSE";
    s1.getInfo();

    return 0;
}