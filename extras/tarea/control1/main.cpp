#include <iostream>

using namespace std;

int main(){
    int filas=5;
    int columnas=5;
    int matriz[filas][columnas]={{1,2,3,4,5},{16,17,18,19,6},{15,24,25,20,7},{14,23,22,21,8},{13,12,11,10,9}};
    int f=filas;
    int c=columnas;
    int x=0;
    int y=0;
    int contador=0;
    while(contador<filas*columnas)
        if(y==f && x<c){
            cout<<" "<<matriz[x][y];
            contador = contador + 1;
            if(x<c-1){
                x=x+1;
            }
            else{
                c=c-1;
                }
        }
        else{
            if(y<f){
                cout<<" "<<matriz[x][y];
                contador = contador + 1;
                if(y<f-1){
                    y=y+1;}
                else{
                    f=f-1;}}
            else{
                if(x>=columnas-c){
                    x=x-1;
                    cout<<" "<<matriz[x][y];
                    contador = contador + 1;}
                else{
                    if(y>=filas-f){
                        y=y-1;
                        cout<<" "<<matriz[x][y];
                        contador = contador + 1;}
                    else{
                        y=f;
                        }
                    }
              }
        }
}
