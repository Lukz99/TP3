//
// Created by juamp on 30/11/2021.
//

#ifndef TP3_JUGADOR_H
#define TP3_JUGADOR_H
#include <string>

using namespace std

class Jugador {
private:
    char nombreJugador;
    int energia = 50;
    int cantidadBombas;
    string objetivos[3];
public:
    Jugador(int);
    ~Jugador();
    void restarEnergia(int);
    void restaurarEnergia()
    int obtenerEnergia();
};


#endif //TP3_JUGADOR_H
