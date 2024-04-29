#include <iostream>
#include <array>

using namespace std;

const int N = 8;
int tablero[N][N] = {0};
int heuristica[N][N] = {22,22,22,22,22,22,22,22,
                        22,24,24,24,24,24,24,22,
                        22,24,26,26,26,26,24,22,
                        22,24,26,28,28,26,24,22,
                        22,24,26,28,28,26,24,22,
                        22,24,26,26,26,26,24,22,
                        22,24,24,24,24,24,24,22,
                        22,22,22,22,22,22,22,22 };
int reynas = 0;

bool validar_mov(int x, int y) {
    if (tablero[x][y] != 0) return false;

    for (int i = 0; i < N; ++i) {
        if (tablero[i][y] != 0 || tablero[x][i] != 0) return false;
    }

    for (int i = x, j = y; i >= 0 && j >= 0; --i, --j) {
        if (tablero[i][j] != 0) return false;
    }

    for (int i = x, j = y; i < N && j < N; ++i, ++j) {
        if (tablero[i][j] != 0) return false;
    }

    for (int i = x, j = y; i >= 0 && j < N; --i, ++j) {
        if (tablero[i][j] != 0) return false;
    }

    for (int i = x, j = y; i < N && j >= 0; ++i, --j) {
        if (tablero[i][j] != 0) return false;
    }

    return true;
}

bool colocar_reyna(int x) {
    if (x == N) return true;

    for (int y = 0; y < N; ++y) {
        if (validar_mov(x, y)) {
            tablero[x][y] = 1;
            ++reynas;
            
            if (colocar_reyna(x + 1)) return true;
            
            tablero[x][y] = 0;
            --reynas;
        }
    }

    return false;
}

void imprimirTablero() {
    cout << "________________\n";
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << tablero[i][j] << " ";
        }
        cout << endl;
    }
    cout << "________________\n";
    cout << "reynas : " << reynas << endl;
    cout << "________________\n";
    cout << "columna   fila\n";
}

int main() {
    if (colocar_reyna(0)) {
        cout << "Solución encontrada:" << endl;
        imprimirTablero();
    } else {
        cout << "No se encontró solución." << endl;
    }

    return 0;
}