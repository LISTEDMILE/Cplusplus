#include <iostream>
#include <algorithm>
#include <string>


using namespace std;

string reverseee(string a ){
    string ans;
    reverse(a.begin(), a.end());
    for (int i =0; i<a.length(); i++){

    
        string word = "";
    while(a[i]!=' ' && i<a.length()){
        word = a[i] + word;
        i++;
    }
    if(word.length() > 0){
        ans = ans + " " + word;
    }
    

}

/// to remove starting extra space......
    return ans.substr(1);
}

int main(){

    // reverse words in string like " This is   what   "  -> "what is This" also remove extra space 
    string a;
    cout << "Enter a string : ";
    getline(cin, a);
    string b = reverseee(a);

    cout << "The reverse string : " << b;

    return 0;
}