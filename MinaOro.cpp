#include "MinaOro.h"
#include <iostream>

MinaOro::MinaOro() {
    nombreClave = 'G';
    nombreEdificio = "mina oro";
    estadoEdificio = 2;

}

MinaOro::~MinaOro() = default;

MinaOro::MinaOro(int cantidadPiedra, int cantidadMadera, int cantidadMetal, int maximoPermitidos) : Edificio(cantidadPiedra,cantidadMadera,cantidadMetal,maximoPermitidos){
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

void MinaOro::declararPropietario(string nombreJugador){
    propietario = nombreJugador;
}
string MinaOro::obtenerPropietario() {
    return propietario;
}