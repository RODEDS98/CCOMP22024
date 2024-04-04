#include <iostream>
#include "jugador.h"

using namespace std;

int main()
{
    int n,a;
    string nam,p;
    string arr[11];   
    cout<<"Ingrese el nombre del jugador"<<endl;
    cin >> nam;
    cout<<"Ingrese el numero del jugador: "<<endl;
    cin >> n;
    cout<<"Ingrese la posicion del jugador: "<<endl;
    cin >> p;
    cout<<"Ingrese la agresividad del jugador: "<<endl;
    cin >> a;
    cout<<""<<endl;
    Playe.set_Nombre(nam);
    Playe.set_Numero(n);
    Playe.set_Posicion(p);
    Playe.set_Agresividad(a);

    Playe.imprimir();

    return 0;
}