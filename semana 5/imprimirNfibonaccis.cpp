#include <iostream>
using namespace std;

int Fibonaci(long long f){

    int t1=1;
    int t2=1;
    int t3;


    if( f == 1||f == 2){            
        return 1;
    }
    else
    { 
        for(int i=3;i<=f;i++){  // t1  t2  t3
                                // 1   1   2         
            t3 = t1 + t2;       // 1   1   2   
            t2 = t3;
            t1 = t2;
        }
        return t3;
    }
}
void Fibonaci_imprimir_n(long long f){

    int t1=1;
    int t2=1;
    int t3;

    if( f == 1){            
        cout<<"1 ";
    }
    else if (f >= 2){
        cout<<"1 1 ";   
    }
    for(int i=3;i<=f;i++){
            
            t3 = t1 + t2;
            t2 = t3;
            t1 = t2;
            cout<<t3<<" "; 
    }

}




int main(){
    int numero;

    cout<< "Ingrese un numero \n"; cin>> numero;
    cout<< "El fibonaci "<<numero<<" es: "<<Fibonaci(numero)<<endl;
    cout<< "Ingrese cuantos fibonaccis quiere imprimir\n"; cin>> numero;
    Fibonaci_imprimir_n(numero);



    return 0;
}