#include <iostream>

using namespace std;
void fun()
{
    // if not static in each func the x will be reinitialize printing 0 every time
    // but with static it is initialized only once and will remain in memory life time of program.....
    static int x = 0;
    cout << "x : " << x++ << endl;
}


class A{
    public:
        A(){
            cout << "Constructor.\n";
        }
        ~A(){
            cout << "Desctructor.\n";
        }
};

int main()
{
    // static means ab ye obj life time rhega program ke jab program khatam tab destructor run hoga....
    if(true){
      static  A abc;
    }
    cout << "end of main()\n";
    return 0;
}