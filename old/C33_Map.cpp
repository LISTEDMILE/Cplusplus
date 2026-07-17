#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;

int main()
{

    // map is used to store key value pairs....
    map<string, int> m;

    // sort automatically on basis of key
    m["one"] = 1;
    m["two"] = 2;
    m["three"] = 3;

    m.insert({"four", 4});
    m.emplace("five", 5);
    m.emplace("five", 6);

    for (auto p : m)
    {
        cout << "\n"
             << p.first << " " << p.second << "\t";
    }

    cout << "\nm['five'] = " << m["five"];
    cout << "\nm.count('five') = " << m.count("five");

    // erase a entry..
    m.erase("five");
    if (m.find("five") != m.end())
    {
        cout << "\nm['five' after erase] = " << m["five"];
    }

    //. find return true if present other wise .end() of the map ...

    if (m.find("one") != m.end())
    {
        cout << "\nm.find('one') = " << "found";
    }
    else
    {
        cout << "\nm.find('one') = " << "not found";
    }
    if (m.find("six") != m.end())
    {
        cout << "\nm.find('six') = " << "not found";
    }
    else
    {
        cout << "\nm.find('one') = " << "found";
    }

    /// to store multiple values per key == multimap

    multimap<string, int> mm;
    mm.emplace("tv", 100);
    mm.emplace("tv", 100);
    mm.emplace("tv", 100);
    mm.emplace("tv", 100);

    for (auto p : mm)
    {
        cout << endl
             << p.first << " " << p.second;
    }

    // erase with loc..
    cout << endl
         << "erase(mm.find('tv'))";
    mm.erase(mm.find("tv"));
    for (auto p : mm)
    {
        cout << endl
             << p.first << " " << p.second;
    }

    mm.erase("tv");

    cout << "\nAfter erase ('tv')\n";
    for (auto p : mm)
    {
        cout << endl
             << p.first << " " << p.second;
    }

    /// unordered map

    unordered_map<string, int> um;
    um.emplace("tv", 100);
    um.emplace("tv", 100);
    um.emplace("tv", 100);
    um.emplace("tv", 100);

    cout << "\nAfter inserting 4 items with same key\n";

    for (auto p : um)
    {
        cout << endl
             << p.first << " " << p.second;
    }
    return 0;
}