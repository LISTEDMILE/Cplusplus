#include <iostream>
using namespace std;

int main(){

    //patern 1
    int a;
    cout << "Enter a no.\n";
    cin >>  a;
    for (int i = 0; i < a; i++){
        for (int j = 0; j < a; j++){
            cout << "* ";
        }
        cout << "\n";
    }


    // P2
    cout << "Enter a no.\n";
    cin >> a;
    for (int i = 1; i <= a; i++){
        for (int j = 1; j <= a;j++){
            cout << j << " ";
        }
        cout << "\n";
    }

    //P3
    cout << "Enter a no.\n";
    cin >>  a;
    for (int i = 0; i < a; i++){
        char start = 'A';
        for (int j = 0; j < a; j++){
            cout << start << " ";
            start++;
        }
        cout << "\n";
    }

    //P4
    cout << "Enter a no.\n";
    cin >>  a;
    for (int i = 0; i < a; i++){
        for (int j = 1; j <=a; j++){
            cout << a * i + j << " ";
        }
        cout << "\n";
    }

    //P5
    cout << "Enter a no.\n";
    cin >>  a;
    for (int i = 1; i <= a; i++){
        for (int j = 0; j < i; j++){
            cout <<  "* ";
        }
        cout << "\n";
    }

    //P6
    cout << "Enter a no.\n";
    cin >>  a;
    for (int i = 1; i <= a; i++){
        for (int j = 0; j < (a-i); j++){
            cout  << " ";
        }
        for (int k = 0; k < i; k ++){
            cout << "*";
        }
            cout << "\n";
    }

    //P7
    cout << "Enter a no.\n";
    cin >>  a;
    for (int i = 1; i <= a; i++){
        for (int j = 0; j < (a-i); j++){
            cout  << " ";
        }
        for (int k = 0; k < i; k ++){
            cout << "* ";
        }
            cout << "\n";
    }

    //P8
    cout << "Enter a no.\n";
    cin >>  a;
    for (int i = 1; i <= a; i++){
        for (int j = 1; j <= i; j++){
            cout << i <<  " ";
        }
        cout << "\n";
    }


    //P9
    cout << "Enter a no.\n";
    cin >>  a;
    for (int i = 1; i <= a; i++){
        for (int j = 1; j <= i; j++){
            cout << j <<  " ";
        }
        cout << "\n";
    }


    //P10
    cout << "Enter a no.\n";
    cin >>  a;
    for (int i = 1; i <= a; i++){
        for (int j = i; j >= 1; j--){
            cout << j <<  " ";
        }
        cout << "\n";
    }

    //P11
    cout << "Enter a no.\n";
    cin >>  a;
    int num = 0;
    for (int i = 1; num <= a; i++){
        for (int j = 1; j <= i; j++){
            cout << ++num <<  " ";
            if(num == a){
                break;
            }  
        }
        if(num == a ){
            break;
        }
        cout << "\n";
    }

        return 0;
}