#include "Mina.h"

Mina::Mina() {
    nombreClave = 'M';
    nombreEdificio = "Mina";
    estadoEdificio = 2;
}

Mina::~Mina() = default;

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
void Mina::declararPropietario(string nombreJugador){
    propietario = nombreJugador;
}
string Mina::obtenerPropietario() {
    return propietario;
}
