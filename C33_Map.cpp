#include <iostream>
#include <map>
using namespace std;


int main(){

    // map is used to store key value pairs....
    map<string,int> m;

    // sort automatically on basis of key 
    m["one"] = 1;
    m["two"] = 2;
    m["three"] = 3;

    m.insert({"four", 4});
    m.emplace("five", 5);
    m.emplace("five", 6);

    for(auto p:m){
        cout << p.first << " " << p.second << "\t";
    }

    return 0;
}