#include <iostream>
#include <array>
#include <cstdlib> // para system("pause")

using namespace std;

const int N = 8;
array<array<int, N>, N> tablero{};
array<array<int, N>, N> accessibility{
    22, 22, 22, 22, 22, 22, 22, 22,
    22, 24, 24, 24, 24, 24, 24, 22,
    22, 24, 26, 26, 26, 26, 24, 22,
    22, 24, 26, 28, 28, 26, 24, 22,
    22, 24, 26, 28, 28, 26, 24, 22,
    22, 24, 26, 26, 26, 26, 24, 22,
    22, 24, 24, 24, 24, 24, 24, 22,
    22, 22, 22, 22, 22, 22, 22, 22
};

void imprimirTablero() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << tablero[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\nAccessibility:\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << accessibility[i][j] << " ";
        }
        cout << "\n";
    }
}

bool validarMov(int row, int col) {
    for (int i = 0; i < N; i++) {
        if (tablero[row][i] == 1 || tablero[i][col] == 1) return false;
    }
    for (int i = 0; i < N; i++) {
        int dx = row - i, dy = col - i;
        if (dx >= 0 && dy >= 0 && tablero[dx][dy] == 1) return false;
        dx = row - i; dy = col + i;
        if (dx >= 0 && dy < N && tablero[dx][dy] == 1) return false;
    }
    return true;
}

bool colocar_reyna(int reina) {
    if (reina == N) return true;
    for (int i = 0; i < N; i++) {
        if (validarMov(reina, i)) {
            tablero[reina][i] = 1;
            if (colocar_reyna(reina + 1)) return true;
            tablero[reina][i] = 0; // Backtrack
        }
    }
    return false;
}

int main() {
    if (!colocar_reyna(0)) {
        cout << "No se encontró solución.\n";
    } else {
        imprimirTablero();
    }
    return 0;
}