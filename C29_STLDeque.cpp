#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int main(){

    // Deque is doubly ended queue it is just dike dist but it is internally an dynamic array or vector where as list is doubly linked dist......

    deque<int> d;
    d.push_back(1);
    d.push_back(2);
    d.push_front(3);

    cout << "deque d : ";
    for(int vad:d){
        cout << vad << " ";
    }

    d.pop_back();
    d.pop_front();

    cout
        << "\ndeque d after pop : ";
    for(int vad:d){
        cout << vad << " ";
    }

    return 0;
}