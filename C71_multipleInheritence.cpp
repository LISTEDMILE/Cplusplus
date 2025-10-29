#include <iostream>
#include <string>

using namespace std;

class Teacher
{
public:
    double salary;
    string subject;
};

class Student
{
public:
    int rollNo;
    string name;
};

class MTechStudents : public Student, public Teacher
{
public:
    void getInfo()
    {
        cout << "name : " << name << endl;
        cout << "subject : " << subject << endl;
        cout << "rollNo : " << rollNo << endl;
        cout << "salary : " << salary << endl;
    }
};

int main()
{

    MTechStudents s1;
    s1.name = "aakash";
    s1.salary = 30000;
    s1.rollNo = 4;
    s1.subject = "CSE";
    s1.getInfo();

    return 0;
}