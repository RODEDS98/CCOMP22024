/**
 * Escriba un programa que reciba una cadena y cuente cuantos numeros
 * tiene dicha cadena
*/
#include <iostream>

using namespace std;

int main(){
    string cad;
    cout << "Ingrese una cadena por favor: ";
    getline(cin, cad);

    int counter{0};
    for( int i = 0; i < cad.length()  ; i++ ) {                
        int val = static_cast<int>(cad.at(i));
        if(val >= 48 && val <= 57)
            counter++;
    }
    
    cout << counter << endl;
    return 0;
}