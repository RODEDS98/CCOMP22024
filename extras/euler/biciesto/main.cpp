#include <iostream>

using namespace std;

int main()
{
    cout << "Ingrese un año para saber si es biciesto: " << endl;
    int x;
    cin >> x;
    if(x%4==0)
    {
        if(x%100!=0)
        {
            cout << "Es bhiciestho" <<endl;
        }
        else
        {
            if(x%400==0)
                cout << "Es visiestho" << endl;
            cout << " No es visiestho" << endl;
        }
    }
    else
        cout << "no es vhisiesto"<< endl;
    return 0;
}
