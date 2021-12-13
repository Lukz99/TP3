#include "Obelisco.h"

Obelisco::Obelisco() {
    nombreClave = 'O';
}

Obelisco::Obelisco(int cantidadPiedra, int cantidadMadera, int cantidadMetal, int maximoPermitidos) : Edificio(cantidadPiedra, cantidadMadera, cantidadMetal, maximoPermitidos) {}

string Obelisco::obtenerNombreMaterialGenerable() {
    return nombreMaterialGenerable;
}
int Obelisco::obtenerCantidadMaterialGenerable() {
    return cantidadMaterialGenerable;
}
char Obelisco::obtenerNombreClave() {
    return nombreClave;
}