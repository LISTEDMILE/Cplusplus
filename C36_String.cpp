#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
int main()
{

    // for valid string we have to add end line character
    char str[] = {'A', 'b', 'c'};
    char str1[] = {'a', 'b', 'c', '\0'};
    char str2[] = "Hello";

    cout << str << endl;
    cout << str1 << endl;
    cout << "Length(str1) = " << strlen(str1) << endl;
    cout << str2 << endl;
    cout << "str2[1] = " << str2[1] << endl;

    char initialString[10];
    cout << "Enter string : " << "\n";
    // cin sirf pehle " " tak input leta h fir ignore.....
    cin >> initialString;

    cout << "Output : " << initialString << "\n";

    char inputString[10];
    // (destination, length, delimitor - where to end the input);
    cin.getline(inputString, 10, '$');
    cout << "inputString = " << inputString << endl;

    /// Original Stringssss....

    /// dynamic hoti h run time pe size change ho skta h...
    string stringhbhai = "This string";
    cout << stringhbhai << endl;
    stringhbhai = "new THis string";
    cout << stringhbhai << endl;

    stringhbhai += "oh ho";
    cout << stringhbhai;

    string firstString = "Ye";
    string secondString = "Ye";
    cout << "Equality = " << (secondString == firstString) << "\n";

    // like check karega jaise a ya y me se y bda order wise...
    cout << "compare = " << (secondString > firstString) << "\n";
    cout << "Size = " << firstString.length() << "\n";

    // input
    string thirdString;
    getline(cin, thirdString);
    cout << "input String : " << thirdString << endl;

     reverse(firstString.begin(), firstString.end());
     cout << "Reverse : " << firstString << endl;
     return 0;
}