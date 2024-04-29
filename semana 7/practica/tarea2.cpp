#include <iostream>
#include <array>

using namespace std;

const int N = 8;
int tablero[N][N] = {0};
int reynas = 0;
int tours_de_longitud[N*N] = {0};

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

void colocar_reyna(int x) {
    if (x == N) {
        imprimirTablero();
        reynas++;
        return;
    }
    for (int y = 0; y < N; ++y) {
        if (validar_mov(x, y)) {
            tablero[x][y] = 1;
            colocar_reyna(x + 1);
            tablero[x][y] = 0;
        }
    }
}

int main() {
    colocar_reyna(0);

    
    cout << "Resultados de los tours:" << endl;
    cout << "Longitud del tour\tCantidad de tours" << endl;
    for (int i = 0; i < N*N; ++i) {
        if (tours_de_longitud[i] > 0) {
            cout << i << "\t\t\t" << tours_de_longitud[i] << endl;
        }
    }

    return 0;
}