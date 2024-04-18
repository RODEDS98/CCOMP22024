#include <iostream>
using namespace std;


int potencia(int base, int exponente){
    int result = 1;
    for(int i=0; i<exponente; i++){
        result= result*base;
    }
    return result;
}

int main(){
    int tresExpCuatro = potencia(3,4);
    cout<<"3  4  is: "<< tresExpCuatro<<endl;


    return 0;
}