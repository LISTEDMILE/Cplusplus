#include <iostream>
#include <string>

using namespace std;

class Teacher
{
private:
    double salary = 0;

public:
    // properties
    string name;
    string dept;
    string subject;

    // methods
    void changeDept(string newDept)
    {
        dept = newDept;
    }

    void setSalary(double s)
    {
        salary = s;
    }
    double getSalary()
    {
        return salary;
    }
};

int main()
{

    // Encapsulation is creating a single unit of both data and function
    // it is used to protect data
    // just like we did by allowing accessing through functions only...
    Teacher t1;
    Teacher t2;
    t2.changeDept("This");
    cout << "t2.dept : " << t2.dept;
    t2.name = "Oye";
    cout << "\nt2.name : " << t2.name << endl;

    t2.setSalary(20000);
    cout << "t2.salary : " << t2.getSalary();

    return 0;
}