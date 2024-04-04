#include <iostream>

using namespace std;

int arreglo(int x,int y){
    int z[x];
    for(int i=0;i<x;i++){
        z[i]=y[x-i-1];}
    return z[x];}

int main()
{
    cout << "Tamaño del arreglo?" << endl;
    int t;
    cin>>t;
    int Arreglo[t];
    for(int i=0;i<t;i++){
        cout <<"Arreglo["<<i<<"] == ";
        int a;
        cin>>a;
        Arreglo[i]=a;}
    int L= arreglo(t,Arreglo[t])
    for(int i=0;i<t;i++){
        cout<<" "<<L[i];}
    return 0;
}
