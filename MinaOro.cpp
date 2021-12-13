#include "MinaOro.h"
#include <iostream>

MinaOro::MinaOro() {
    nombreClave = 'G';
}

MinaOro::MinaOro(int cantidadPiedra, int cantidadMadera, int cantidadMetal, int maximoPermitidos) : Edificio(cantidadPiedra,cantidadMadera,cantidadMetal,maximoPermitidos){
    estadoEdificio = 2;
}

string MinaOro::obtenerNombreMaterialGenerable() {
    return nombreMaterialGenerable;
}
int MinaOro::obtenerCantidadMaterialGenerable() {
    return cantidadMaterialGenerable;
}
char MinaOro::obtenerNombreClave() {
    return nombreClave;
}