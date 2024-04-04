#ifndef JUGADOR_H
#define JUGADOR_H
#include <string>

using namespace std;

class jugador
{
    public:
        int num,agre;
        string name,pos;

        jugador();
        jugador(string n,int num, string pos, int ag);
        virtual ~Jugador();
        void set_name(string n);
        void set_numero(int num);
        void set_posicion(string pos);
        void set_agresividad(int ag);
        void imprimir();

};

#endif // JUGADOR_H