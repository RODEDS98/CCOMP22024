#include <iostream>
#include <string>


using namespace std;

int main(){
    string cad;
    cout<<"Ingrese una cadena: ";
    getline(cin,cad);
    char c;
    for(int i=0; cad.size(); i++){
        c=cad.at(i);
        int val=static_cast <int> (c);
        if(val >= 97 && val <= 122){
            cad.at(i) = c -32;   
        }
    }

    cout << cad << endl;
    return 0;




}