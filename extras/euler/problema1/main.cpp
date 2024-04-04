#include <iostream>

using namespace std;

int fibonaci(int x){
    if(x<4){
        return x;}
    return fibonaci(x-1)+ fibonaci(x-2);
}
int pares(int x){
    int a = 0;
    for(int i;i<x;i++){
        int b =fibonaci(i);
        if(b%2==0);
            a=a+b;
    return a;
    }
}


int main()
{
    int num;
    cout << "ingrese un numero!" << endl;
    cin >> num;
    cout << "Los sumatoria de los numeros pares fibonaci menores que : "<<num<<endl;
    cout<<"es: "<<pares(num);
    return 0;
}
