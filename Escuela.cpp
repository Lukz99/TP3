#include "Escuela.h"

Escuela::Escuela() : Edificio(){
    nombreClave = 'E';
}

Escuela::Escuela(int cantidadPiedra, int cantidadMadera, int cantidadMetal, int maximoPermitidos) : Edificio(cantidadPiedra,cantidadMadera,cantidadMetal,maximoPermitidos){}

string Escuela::obtenerNombreMaterialGenerable() {
    return nombreMaterialGenerable;
}
int Escuela::obtenerCantidadMaterialGenerable() {
    return cantidadMaterialGenerable;
}
char Escuela::obtenerNombreClave() {
    return nombreClave;
}