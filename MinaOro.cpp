#include "MinaOro.h"
#include <iostream>

MinaOro::MinaOro() {}

MinaOro::MinaOro(int cantidadPiedra, int cantidadMadera, int cantidadMetal, int maximoPermitidos) : Edificio(cantidadPiedra,cantidadMadera,cantidadMetal,maximoPermitidos){
    estadoEdificio = 2;
}
