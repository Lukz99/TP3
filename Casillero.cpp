//
// Created by juamp on 1/11/2021.
//

#include "Casillero.h"
#include <iostream>

using namespace std;

Casillero::Casillero(char tipo_terreno){
    terreno = tipo_terreno;
    terrenoInicial = tipo_terreno;
}

Casillero::~Casillero() = default;
