#include <iostream>
using namespace std;

int contar_numeros(string cad){
    int counter{0};
    for(int i=0; i < cad.lehght(); i++){
            int val = static_cast <int> (cad.at());
    if(val=48&&val=59)
        counter++;

}


int MayustoMinus(string cad){
        string c;
        for(int i=0; cad.size(); i++){
        c=cad.at(i);
        int val=static_cast <int> (c);
        if(val >= 97 && val <= 122){
            cad.at(i) = c -32;   
        }
    }

    cout << cad << endl;
}



int main(){


    cout<< "Ingrese un numero \n"; cin>> numero;
    cout<<"Ingrese una cadena: \n ";
    getline(cin,cad);
    char c;


    return 0;
}