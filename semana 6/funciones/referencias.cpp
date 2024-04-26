#include <iostream>

using namespace std;

int main() {
    int x = 100;

    int &ref = x;
    ref++;
    cout << x << endl;
    cout << ref << endl;
    ref = 1000;
    cout << x << endl;

    int y = 10;
    ref = y;
    cout << ref << endl;
}