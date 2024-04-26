#include <iostream>

using namespace std;

void intercambio(int &x, int &y);

int main() {
    int a = 10;
    int b = 20;
    intercambio(a, b);

    cout << a << endl;
    cout << b << endl;
}

void intercambio(int &x, int &y) {
    int tmp = x;
    x = y;
    y = tmp;
}