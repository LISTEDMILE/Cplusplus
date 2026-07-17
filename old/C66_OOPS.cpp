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

    // basically the class is the blue print or group of objects.
    // like the design for car is a class teh actually manufactured cars are objects.
    // the objects created using this class is called an antity
    // the properties are associated with each antity.

    
    // access modifiers ====
    // private - only accessible inside class
    // public - accessible to everyone
    // protected - accessible to class and its derieved class
    //   - by default all are private...
    Teacher t1;
    Teacher t2;
    t2.changeDept("This");
    cout << "t2.dept : " << t2.dept;
    t2.name = "Oye";
    cout << "\nt2.name : " << t2.name << endl;

    // cout << t2.salary; // try removing comment give error.
    t2.setSalary(20000);
    cout << "t2.salary : " << t2.getSalary();

    return 0;
}