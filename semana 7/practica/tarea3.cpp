#include <iostream>
#include <string>
using namespace std;
void mayostominus(string& cad){

    char c;
    for(int i=0; i < cad.size(); i++){
        c=cad.at(i);
        int val=static_cast <int> (c);
        if(val >= 97 && val <= 122){
            cad.at(i) = c -32;   
        }
        else if(val < 97 || val > 122){  //Si tiene algo que no es letra lo elimina de la cadena
            cad.at(i) = cad.at(i+1);
            i++;   
        }
    }

    cout <<"primeramente se combirtio a minusculas"<< cad << endl;

}

bool testPalindrome(const std::string& pal, int val, int count) {
    char c=pal.at(val);
    int caracter_to_num = static_cast <int> (c);
    if (val >= count) return true;
    if (pal[val] != (caracter_to_num >= 97 && caracter_to_num <= 122)) return testPalindrome(pal, val + 1, count);
    else if (pal[count] != (caracter_to_num >= 97 && caracter_to_num <= 122)) return testPalindrome(pal, val , count + 1);
    else if (pal[val] == pal[count]) return testPalindrome(pal, val + 1, count - 1);


    return false;
}

int main(){
    string cad;
    cout<<"Ingrese una cadena: ";
    getline(cin,cad);
    mayostominus(cad);
    cout <<"SEGUNDO\n\n"<< cad << endl;
    testPalindrome(cad, 0, cad.size()-1)?cout<<"Es palindromo":cout <<"No es palindromo";

    return 0;
}