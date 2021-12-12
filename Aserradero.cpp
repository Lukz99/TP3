#include "Aserradero.h"

Aserradero::Aserradero() : Edificio() {}

Aserradero::Aserradero(int piedra, int madera, int metal, int maximoPermitidos) : Edificio(piedra, madera, metal, maximoPermitidos) {}

string Aserradero::obtenerNombreMaterialGenerable() {
    return nombreMaterialGenerable;
}
int Aserradero::obtenerCantidadMaterialGenerable() {
    return cantidadMaterialGenerable;
}