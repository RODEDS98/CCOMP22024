#include <iostream>

using namespace std;

int main()
{
    cout << "Escriba un numero para saber si es primo" << endl;
    int x;
    bool a = false;
    cin >> x;
    for(int i=2;i<x;i++)
    {
        if(x%i==0)
            a = true;

    }
    if(a == true)
        cout << "No es primo " <<endl;
    else
        cout << "Es primo" <<endl;
    return 0;
}
