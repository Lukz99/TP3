#include "CasilleroInaccesible.h"
#include <iostream>

using namespace std;

CasilleroInaccesible::CasilleroInaccesible(char terreno, int x, int y) : Casillero(terreno){
    fila = x;
    columna = y;
}

void CasilleroInaccesible::mostrar() {
    cout << getTerreno();
}

void CasilleroInaccesible::modificar(char nuevoNombre) {
    terreno = nuevoNombre;
}

char CasilleroInaccesible::getTerreno() {
    return terreno;
}

char CasilleroInaccesible::getInicial() {
    return terrenoInicial;
}



