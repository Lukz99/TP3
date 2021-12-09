#include "Casillero.h"
#include <iostream>

using namespace std;

Casillero::Casillero(char tipo_terreno){
    terreno = tipo_terreno;
    terrenoInicial = tipo_terreno;
}

Casillero::~Casillero() = default;
