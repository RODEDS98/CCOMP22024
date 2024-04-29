#include <iostream>
#include <array>

using namespace std;

const int col = 8;
const int row = 8;
int reynas = 0;
array<array<int,col>,row> tablero{0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,
                                   0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,
                                   0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,
                                   0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,};

void imprimirTablero(){
    system("cls");
    cout<<"________________\n";
    for (int y = 0; y < col; y++) {
        for (int x = 0; x < row; x++) {
            cout << tablero[x][y]<<" ";
        }
        cout<<"\n";
    }
    cout<<"________________\n";
    cout<<"reynas : "<<reynas<<"\n";
    cout<<"________________\n";
    cout<<"columna   fila\n";

}

bool validar_mov(int pos_x,int pos_y) {  //fila comulmna

    if(tablero[pos_x-1][pos_y-1]!=0) return false;
    for (int pos_fila : tablero[pos_y-1]) { //comparando las filas de una columna
        if(pos_fila!=0)    return false;
    }

    for (int j=0; j<col;j++) {  //comparando las columnas de una fila
        if(tablero[j][pos_x-1]!=0)    return false;
    }
    reynas++;
    return true;
}  
   
void colocar_reyna(int pos_x,int pos_y) { //fila comulmna
    if (validar_mov(pos_x,pos_y)){ 
        tablero[pos_x-1][pos_y-1]=1;
        imprimirTablero();
    }
    else {
        imprimirTablero();
        cout<<"movimiento denegado\n";}
   
}



int main() {

    int pos_x,pos_y;
    cout<<"Ingresaras la posicion de la reyna  columna , fila ";
    imprimirTablero();
    do{ 
        cout<<"   ";
        cin>>pos_y;
        cout<<"\t   ";
        cin>>pos_x;
        colocar_reyna(pos_x, pos_y);  //fila columna

    }
    while(reynas<=8);
    cout<<"Encontraste una solucion! ";
    return 0;

}
