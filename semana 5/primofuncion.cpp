#include <iostream>
using namespace std;

// Evalua si unb numero es primo.
bool evaluar_primo(long long evaluar){
    if( evaluar == 2 ) return true;
    else if(!(evaluar%2) || evaluar ==1 ) return false;             // (0) %2=algo => [1] !: false    / (1) %2=algo => [1] !: false /  (2) %2 = 0 => [0] !: true /  (3) %2=algo => [1] negado: true    //
    for(int i=2 ; i<=evaluar/2 ; i++){         //       no es primo                           no es primo                   es primo                       es primo
        if(!(evaluar%i)){     // 2 3
            return false;
        }

    }
    return true;
}

void imprimir_primo(long cantidad){
    int n{0},i{1};
    cout<<"Los "<< cantidad <<" primeros numeros primos son:\n";
    while(n<cantidad){   
        // Si el numero ingresado es primo, lo imprime.                      //        n=0  n=0  n=1  n=2  n=2  n=3
        if (evaluar_primo(i)){            
            cout<<i;   //imprime el numero evaluado que es primo
            n++;
            cout<<"  ";
        }
        i++;
    }
}

int main(){

    

    long long numero,cantidad;
    bool esprimo;

    cout<< "Ingrese un numero \n"; cin>> numero;
    esprimo = evaluar_primo(numero); // 3   (true: 1)  false: 0

    (esprimo)?cout << "Es primo\n" :  cout << "No es primo"<<endl;

    cout<< "Imprime la cantidad de primos a imprimir: \n"; cin>> cantidad;
    imprimir_primo(cantidad);

    return 0;
}