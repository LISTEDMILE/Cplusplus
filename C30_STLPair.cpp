#include <iostream>
#include <vector>
using namespace std;

int main()
{

    // used when we need a pair of values together
    pair<int, int> p = {1, 5};

    // to access them ....
    cout << "P.first : " << p.first;
    cout << "\nP.second : " << p.second;

    pair<int, pair<int, string>> pa = {1, {1, "a"}};
    cout << "\npa.first : " << pa.first;
    cout << "\npa.second.first : " << pa.second.first;
    cout << "\npa.second.second : " << pa.second.second;

    vector<pair<int, int>> arr = {{1, 2}, {1, 4}, {4, 5}, {3, 5}};
    cout << "\nVector of Pairs : ";
    for (auto val : arr)
    {
        cout << val.first << " " << val.second << "\t";
    }

    // dono same kam karte h bas fark h ki push back direct element ko push karta h aur emplace back pehle use object me convert karta h....
    arr.push_back({4, 5});
    arr.emplace_back(6, 7);
    cout << "\nVector of pairs after push and emplace : ";
    for (auto val : arr)
    {
        cout << val.first << " " << val.second << "\t";
    }
}