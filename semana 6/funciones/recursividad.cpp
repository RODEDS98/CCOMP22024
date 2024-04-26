#include <iostream>
using namespace std;
/* iterativo */
int fibo(long long f){

    int t1=1;
    int t2=1;
    int t3;


    if( f == 1||f == 2){            
        return 1;
    }
    else
    { 
        for(int i=3;i<=f;i++){  // t1  t2  t3
                                // 1   1   2         
            t3 = t1 + t2;       // 1   1   2   
            t2 = t3;
            t1 = t2;
        }
        return t3;
    }
}

/* recursivo */
int fibo_rec(int n) {
    if(n == 1 || n == 0) {
        return 1;
    } else {
        return fibo_rec(n-2) + fibo_rec(n - 1);
    }
}

/*factorial 
 n! = n * (n-1)!
*/
int factorial(int n) {
    if(n == 1)
        return 1;
    else
        return n * factorial(n-1);
}


 int main(){
    int numero;

    cout<<"Ingrese un numero: ";
    cin>>numero;

    cout << "\nEl " << numero << " fib es: " << fibo(numero) << endl;
    cout << "\nEl " << numero << " fib es: " << fibo_rec(numero);

    cout << "\nEl " << numero << " factorial de N es: " << factorial(numero);
    return 0;
 }