#include <iostream>
#include <vector>
#include <list>
using namespace std;

int main(){

    // list is like array but it is doubly linked list....

    list<int> l;
    l.push_back(1);
    l.push_back(2);
    l.push_front(3);

    cout << "List l : ";
    for(int val:l){
        cout << val << " ";
    }

    l.pop_back();
    l.pop_front();

    cout
        << "\nList l after pop : ";
    for(int val:l){
        cout << val << " ";
    }

    return 0;
}