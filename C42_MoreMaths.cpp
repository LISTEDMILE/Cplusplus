#include <iostream>
#include <algorithm>

using namespace std;

void printDigits(int a ){
    while(a!=0){
        int digits = a % 10;
        cout << digits << "\t";
        a /= 10;
    }
    cout << "\n";
}

void Armstrong(int a){
    int b = a;
    int ans=0;
    while(a!=0){
        int digits = a % 10;
        ans = ans + digits ^ 3;
        a/=10;
        
    }
    if(ans == b){
        cout << b << " is an armstrong no.\n";

    }
    else{
        cout << b << " is not an armstrong no.\n";
    }
}

int GCD(int a,int b){
    //Euclid's Algorithm...
    while (a>0 && b>0){
        if(a>b){
            a = a % b;

        }
        else{
            b = b % a;
        
        }
    }
    if(a == 0){
        return b;
    }
    else{
        return a;
    }
}

int LCM(int a ,int b){
    int gcd = GCD(a, b);
    return (a * b / gcd);
}

int reverseNum(int a){
    int ans = 0;
    while(a!=0){
        int digit = a % 10;
        if(ans > INT16_MAX/10 || ans < INT16_MIN/10){
            return 0;
        }
        ans = ans * 10 + digit;
        a /= 10;
    }
    return ans;
}

int main(){

    int a = 454545;
    printDigits(a);

    int b = 153;
    Armstrong(b);

    int c = 12;
    int d = 8;
    int ans = GCD(c,d);
    cout << ans << " is the GCD\n";

    int ansLCM = LCM(c, d);
    cout << ansLCM << " is the LCM\n";

    int e = 8098;
    cout << "Reverse of " << e << " : " <<  reverseNum(e) << endl;

    int f = 2332;
    int checkPalindrome = reverseNum(f);
    if(checkPalindrome == f){
        cout << f << " is palindrome\n";
    }
    else{
        cout << f << " is not palindrome\n";
    }

    return 0;
}