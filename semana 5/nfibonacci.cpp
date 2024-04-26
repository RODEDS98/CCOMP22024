#include <iostream>

using namespace std;
 int main(){
    int numero;
    int t1=1;
    int t2=1;
    int t3;

    cout<<"Ingrese un numero: ";
    cin>>numero;
    if( numero == 1||numero == 2){            
        cout << "El " << numero << " fib es: " << 1;
    }
    else
    { 
        for(int i=3;i<=numero;i++){

            t3 = t1 + t2;
            t1 = t2;
            t2 = t3;
        }
        cout << "El " << numero << " fib es: " << t3;
    }
    return 0;
 }