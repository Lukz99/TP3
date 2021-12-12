#include "CasilleroInaccesible.h"
#include <iostream>

using namespace std;

CasilleroInaccesible::CasilleroInaccesible(char terreno) : Casillero(terreno){}

void CasilleroInaccesible::mostrar() {
    cout << obtenerTerreno();
}

void CasilleroInaccesible::modificar(char nuevoNombre) {
    terreno = nuevoNombre;
}

char CasilleroInaccesible::obtenerTerreno() {
    return terreno;
}

char CasilleroInaccesible::obtenerInicial() {
    return terrenoInicial;
}



