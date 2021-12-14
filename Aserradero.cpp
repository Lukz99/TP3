#include "Aserradero.h"

Aserradero::Aserradero() : Edificio() {
    nombreClave = 'A';
    nombreEdificio = "aserradero";
    estadoEdificio = 1;
}

Aserradero::~Aserradero() = default;

Aserradero::Aserradero(int piedra, int madera, int metal, int maximoPermitidos) : Edificio(piedra, madera, metal, maximoPermitidos) {}

string Aserradero::obtenerNombreMaterialGenerable() {
    return nombreMaterialGenerable;
}
int Aserradero::obtenerCantidadMaterialGenerable() {
    return cantidadMaterialGenerable;
}
char Aserradero::obtenerNombreClave() {
    return nombreClave;
}

void Aserradero::declararPropietario(string nombreJugador){
    propietario = nombreJugador;
}
string Aserradero::obtenerPropietario() {
    return propietario;
}
