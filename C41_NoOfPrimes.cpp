#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<bool> noOfPrime(int a){
    vector<bool> test(a + 1, true);
    int count=0;
    for (int i = 2; i < a;i++){
        if(test[i]){
            count++;
            for (int j = i * 2; j < a; j=j+1){
                test[j] = false;
            }
        }
    }
    return test;
}

bool isPrime(int a){
    for (int i = 2; i *i <= a; i++){
        if(a%i == 0){
            return false;
        }

    }
    return true;
}

int main(){

    int a;
    cout << "Enter a no. : ";
    cin >> a;
    bool ansPrime = isPrime(a);
    if(ansPrime){
        cout << a << " is prime\n";
    }
    else{
        cout << a << " is non Prime\n";
    }

    // Sieve of Eratosthenes....
    cout << "Enter a range to find no of primes : ";
    cin >> a;
    vector<bool> primeList = noOfPrime(a);
    cout << "Prime no. are : ";
    for (int i = 2; i<a; i++){
        if(primeList[i]){
            cout << i << "\t";
        }
    }
        return 0;
}