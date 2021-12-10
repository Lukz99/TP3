#ifndef TP3_VERTICE_H
#define TP3_VERTICE_H
#include "Casillero.h"
#include "CasilleroConstruible.h"
#include "CasilleroTransitable.h"
#include "CasilleroInaccesible.h"


class Vertice {
    // Atributos
private:
    char tipoCasilla;
    int posicionFila, posicionColumna;
    CasilleroConstruible* construible;
    CasilleroTransitable* transitable;
    CasilleroInaccesible* inaccesible;
    Vertice* verticeSuperior;
    Vertice* verticeDerecho;
    Vertice* verticeInferior;
    Vertice* verticeIzquierdo;

    // Metodos
public:
    Vertice();
    Vertice(char tipoTerreno, int x, int y);
    bool edificioConstruido();
    Vertice* buscarVerticePorPosicion(Vertice* verticeInicial,int posFila,int posColumna);
    void direccionarVerticeSuperior(Vertice* verticeSuperior);
    void direccionarVerticeDerecho(Vertice* verticeDerecho);
    void direccionarVerticeInferior(Vertice* verticeInferior);
    void direccionarVerticeIzquierdo(Vertice* verticeIzquierdo);
    int obtenerPosicionFila();
    int obtenerPosicionColumna();
    Vertice* obtenerVerticeSuperior();
    Vertice* obtenerVerticeDerecho();
    Vertice* obtenerVerticeIzquierdo();
    Vertice* obtenerVerticeInferior();
    CasilleroConstruible* obtenerCasilleroConstruible();
    CasilleroTransitable* obtenerCasilleroTransitable();
    CasilleroInaccesible* obtenerCasilleroInaccesible();
    char obtenerCasilla();
    void construirEdificio(string, Casillero***);
    ~Vertice();

};

#endif //TP3_VERTICE_H