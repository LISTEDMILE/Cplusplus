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

    cout << "\n";

    //P12
    cout << "Enter a no.\n";
    cin >>  a;
    for (int i = 1; i <= a; i++){
        for (int k = 1; k <= i; k++){
            cout << " ";
        }
            for (int j = 1; j <= a - i + 1; j++)
            {
                cout << i;
            }

        cout << "\n";
    }


    //P13
    cout << "Enter a no.\n";
    cin >>  a;
    for (int i = 1; i <= a; i++){
        for (int l = 1; l <= a - i; l++){
            cout << " ";
        }
            for (int k = 1; k <= i; k++)
            {
                cout << k;
            }
            for (int j = i-1; j >= 1; j--)
            {
                cout << j;
            }

        cout << "\n";
    }



    //P14
    cout << "Enter a no.\n";
    cin >>  a;
    for (int i = 1; i <= a; i++){
        for (int l = 1; l <= a - i; l++){
            cout << " ";
        }
            for (int k = 1; k <= i; k++)
            {
                if(k == 1){
                    cout << "*";
                }
                else{
                    cout << " ";
                }
                
            
            }
            for (int j = i-1; j >= 1; j--)
            {
                if(j == 1){
                    cout << "*";
                }
                else{
                    cout << " ";
                }
            }

        cout << "\n";
    }


    //P15
    cout << "Enter a no.\n";
    cin >>  a;
    int s;
    for (int i = -1*(a-1); i <= a-1; i++){
        s = abs(i);
        for (int l = 1; l <=  s; l++){
            cout << " ";
        }
       for (int k = -(a-s-1); k <= (a-s-1); k++)
       {
            if(k == (a-s-1) || k == (-(a-s-1))){
                cout << "*";
            }
            else{
                cout << " ";
            } 
        }
        cout << "\n";
    }

        return 0;
}