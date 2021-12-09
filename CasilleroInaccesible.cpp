//
// Created by juamp on 3/11/2021.
//

#include "CasilleroInaccesible.h"
#include <iostream>

using namespace std;

CasilleroInaccesible::CasilleroInaccesible(char terreno) : Casillero(terreno){}

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



