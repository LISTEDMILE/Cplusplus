#include <iostream>
#include <string>

using namespace std;

class Teacher
{
private:
    double salary;

public:
    string name;
    string dept;
    string subject;

    // constructor overloading - it is when we use same constructor name obvious constructor name is equal to class name and but different parameters like no. of paramters or type of parameters....

    // constructor
    // 3 type of constructor --
    // 1. non-parmaterized.....
    Teacher()
    {
        salary = 1000;
    }

    // 2. parameterized..
    Teacher(string name, string d, string su, double s)
    {
        // (this->) it is a keyword used to show this property is of object which is to be used.
        // this basically is a pointer pointing to obj.
        // so basically this->  is equals to (*this).prop ----...
        this->name = name;
        dept = d;
        subject = su;
        salary = s;
    }

    // 3. copy
    // used to copy one object ot another...
    // if not given the copy constructor this way it will copy the whole obj as it is ..... similar to manual..

    // ab copy karne ke do tareeke h pehla
    // - sirf data copy karo aur ek proper nya obj with same value create kardo. jaiye is ex me => shallow copy - matlab jo value h as it is copy hongi like is Teacher me val thi as it is copy ho gyi. ya Student me ek ptr bhi h wo bhi aise hi copy ho gya matlab if us ptr pe change kiya to jaise hmne s1 ko s2 me copy kiya to agar s2 me change kiya ptr me to s1 me bhi update hoga khud se hi chahe s1 we have not touched because they both are pointing the same loc......

    // - second -- > Deep copy -> isme jo pointers bhi copy honge na to ptr pe value copy hogi pointers nye hi bnenge...
    Teacher(Teacher &obj)
    { // pass by reference
        this->name = obj.name;
        this->dept = obj.dept;
        this->subject = obj.subject;
        this->salary = obj.salary;
    }

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
    void getInfo()
    {
        cout << "name : " << name << endl;
        cout << "dept : " << dept << endl;
        cout << "subject : " << subject << endl;
        cout << "salary : " << salary << endl;
    }
};

class Student
{
public:
    string name;
    // cgpa pointer
    double *cgpaPointer;
    Student(string name, double cgpa)
    {
        this->name = name;
        // pointer ki loc pe double ki memory allocate kardi dynamically.
        // ye memory heap me allocate hori h kyoki dynamic allocation heap se hi hota h..
        cgpaPointer = new double;

        // shallow copy..
        *cgpaPointer = cgpa;

        // for deep copy..
        // *cgpaPointer = *cgpa;
    }
    void getInfo()
    {
        cout << "name : " << name << endl;
        cout << "cgpa : " << *cgpaPointer << endl;
    }
};

int main()
{

    // at creation or of object the constructor function is called itself even we don't create by default it is run
    // constructor ka kam hi h initialize karna objects ko. at time of creation of object it is called
    // it also includes memory allocation for objects , initializationn of values.
    //  constructor ka nam same hona chahiye class name se
    // return type nhi hona chahiye..
    // aur isko normally alag se bar bar call nhi kar skte only creation of object ke time.

    // aur hmesha -- public -- hona chahiye kyoki ye at creation time run hoga khud to main function ko access hona chahiye iska....

    Teacher t2;
    t2.changeDept("This");
    cout << "t2.dept : " << t2.dept;
    t2.name = "Oye";
    cout << "\nt2.name : " << t2.name << endl
         << endl;

    // we have not run the setSalary function but defined salary at constructor....
    cout << "t2.salary : " << t2.getSalary() << endl
         << endl;

    Teacher t1("Name", "Dept", "Subject", 300);
    t1.getInfo();
    cout << endl;

    Teacher t3(t1);
    t3.getInfo();
    cout << endl;

    Student s1("Rahul", 10);
    // default copy constructor..
    Student s2(s1);
    s2.getInfo();

    *s2.cgpaPointer = 9.9;
    s2.getInfo();
    s1.getInfo();

    return 0;
}