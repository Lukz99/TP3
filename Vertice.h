#ifndef TP3_VERTICE_H
#define TP3_VERTICE_H
#include "Arista.h"
#include "Casillero.h"
#include "CasilleroConstruible.h"
#include "CasilleroTransitable.h"
#include "CasilleroInaccesible.h"


class Vertice {
    // Atributos
private:
    CasilleroConstruible* construible;
    CasilleroTransitable* transitable;
    CasilleroInaccesible* inaccesible;
    Vertice* verticeSuperior;
    Vertice* verticeDerecho;
    Vertice* verticeInferior;
    Vertice* verticeIzquierdo;
    Arista* aristaSuperior;
    Arista* aristaDerecha;
    Arista* aristaInferior;
    Arista* aristaIzquierda;

    // Metodos
public:
    Vertice();

    Vertice(char tipoTerreno, int x, int y);
    ~Vertice();

};

#endif //TP3_VERTICE_H