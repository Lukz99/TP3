//
// Created by juamp on 30/11/2021.
//

#ifndef TP3_JUGADOR_H
#define TP3_JUGADOR_H
#include <string>
#include "Material.h"

using namespace std;

class Jugador {
private:
    string nombreJugador;
    Material *materiales;
    string objetivos[3];
    int energia = 50;
public:
    Jugador(int);
    ~Jugador();
    void restarEnergia(int);
    void restaurarEnergia();
    int obtenerEnergia();
    bool objetivoPrincipalCumplido();
    bool objetivosSecundariosCumplidos();
};


#endif //TP3_JUGADOR_H
