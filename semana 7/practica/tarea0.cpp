#include <iostream>
#include <array>
#include <limits> 

using namespace std;

const int N = 8;
int casillas=0;
array<array<int, N>, N> tablero{};
array<array<int, N>, N> visited{};
array<int, N> horizontal{2, 1, -1, -2, -2, -1, 1, 2};
array<int, N> vertical{-1, -2, -2, -1, 1, 2, 2, 1};
array<array<int, N>,N>  accessibility{  2, 3, 4, 4, 4, 4, 3, 2,
    3, 4, 6, 6, 6, 6, 4, 3,
    4, 6, 8, 8, 8, 8, 6, 4,
    4, 6, 8, 8, 8, 8, 6, 4,
    4, 6, 8, 8, 8, 8, 6, 4,
    4, 6, 8, 8, 8, 8, 6, 4,
    3, 4, 6, 6, 6, 6, 4, 3,
    2, 3, 4, 4, 4, 4, 3, 2
};

bool validar_move(int row, int col) {
    return row >= 0 && row < N && col >= 0 && col 
            < N && tablero[row][col] == 0;
}

void nueva_accesibilidad(int row, int col) {
    for (int i = 0; i < N; ++i) {
        int newRow = row + vertical[i];
        int newCol = col + horizontal[i];
        if (newRow >= 0 && newRow < N && newCol >= 0 &&
                newCol < N && tablero[newRow][newCol] == 0) {
                    --accessibility[newRow][newCol];
        }
    }
}


void imprimirTablero(){
    system("cls");
    cout<<"_______________________         _______________\n";
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            if (tablero[x][y]<=9)
                cout << " "<< tablero[x][y]<< " ";
            else 
                cout << tablero[x][y]<< " ";
        }
        cout <<"\t";

        for (int z = 0; z < N; z++) {
            cout << visited[z][y] << " ";
        }
    cout<<"\n";
    }
    cout<<"\n";        
    cout<<"______________________\n";
    cout<<" casillas usadas : "<<casillas<<"\n";
    cout<<"______________________\n";
    //cout<<"columna   fila\n";
}

bool tourking(int moveCount, int row, int col) {
    tablero[row][col] = moveCount; // Marca el tablero en la posición actual con el número de movimiento
    visited[row][col] = 1;
    nueva_accesibilidad(row, col);  // Actualiza los valores de accesibilidad después de este movimiento
    casillas++;
    if (moveCount == N * N) { // Si el contador de movimientos alcanza N*N, significa que todas las casillas fueron visitadas
        imprimirTablero(); // Imprime el tablero como una solución válida del tour
        return true;
    }

    // Preparar para buscar el próximo movimiento
    int minAccessibility = numeric_limits<int>::max(); // Inicializa el mínimo de accesibilidad con un valor muy alto
    array<pair<int, int>, N> nextMoves; // Almacena los próximos movimientos posibles

    int numMoves = 0; // Contador para los próximos movimientos posibles
    for (int i = 0; i < N; ++i) {
        int nextRow = row + vertical[i]; // Calcula la próxima fila basada en el movimiento vertical
        int nextCol = col + horizontal[i]; // Calcula la próxima columna basada en el movimiento horizontal
        if (validar_move(nextRow, nextCol)) { // Verifica si el movimiento es válido (dentro del tablero y no visitado)
            int acc = accessibility[nextRow][nextCol]; // Obtiene el número de accesibilidad para el nuevo cuadro
            if (acc < minAccessibility) { // Si este cuadro es más accesible que los anteriores
                minAccessibility = acc; // Actualiza el mínimo de accesibilidad
                numMoves = 0; // Reinicia el contador de movimientos posibles
                nextMoves[numMoves++] = {nextRow, nextCol}; // Guarda este movimiento como un posible próximo paso
            } else if (acc == minAccessibility) { // Si este cuadro tiene la misma accesibilidad que el mínimo actual
                nextMoves[numMoves++] = {nextRow, nextCol}; // Añade este movimiento a los posibles próximos pasos
            }
        }
    }

    // Intenta todos los mejores movimientos (menor accesibilidad)
    for (int i = 0; i < numMoves; ++i) {
        int nextRow = nextMoves[i].first; // Extrae la fila del próximo movimiento
        int nextCol = nextMoves[i].second; // Extrae la columna del próximo movimiento
        if (tourking(moveCount + 1, nextRow, nextCol)) { // Llama recursivamente a solveKT para el próximo movimiento
            return true; // Si la llamada recursiva retorna verdadero, propaga este verdadero hacia arriba (solución encontrada)
        }
    }

    tablero[row][col] = 0; // Si no se encontraron soluciones desde esta configuración, hace backtrack (restablece el tablero)
    return false; // Retorna falso indicando que no se encontró una solución desde este punto
}

int main() {
    if (!tourking(1, 0, 0)) { // You can start from any corner, here it starts at (0,0)
        cout << "No solution exists." << endl;
    }
    return 0;
    return 0;
}

