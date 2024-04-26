#include <iostream>
#include <string>

using namespace std;

int contar_numeros(string cad){
    int counter{0};
    for(int i=0; i < cad.size(); i++){
        int val = static_cast <int> (cad.at(i));
        if(val>=48 && val<=57)
            counter++;
    
    }
    return counter;
}

string MinustoMayus(string cad){
        char c;
        for(int i=0;i < cad.size(); i++){
            c=cad.at(i);
            int val=static_cast<int> (c);
            if(val >= 97 && val <= 122){
                cad.at(i) = c -32;   
            }
    }

    return cad;
}



int main(){

    string numero;
    cout<< "Ingrese una cadena de numeros  \n";
    getline(cin,numero);
    cout<<contar_numeros(numero);
    cout<<"\nIngrese una cadena de letras \n ";

    getline(cin,numero);
    cout<<MinustoMayus(numero);

    return 0;
}