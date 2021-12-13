#include "Mina.h"

Mina::Mina() {
    nombreClave = 'M';
}

Mina::Mina(int cantidadPiedra, int cantidadMadera, int cantidadMetal, int maximoPermitidos) : Edificio(cantidadPiedra,cantidadMadera,cantidadMetal,maximoPermitidos){}

string Mina::obtenerNombreMaterialGenerable() {
    return nombreMaterialGenerable;
}
int Mina::obtenerCantidadMaterialGenerable() {
    return cantidadMaterialGenerable;
}
char Mina::obtenerNombreClave() {
    return nombreClave;
}