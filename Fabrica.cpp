#include "Fabrica.h"

Fabrica::Fabrica() : Edificio(){
    nombreClave = 'F';
    nombreEdificio = "fabrica";
    estadoEdificio = 2;

}

Fabrica::~Fabrica() = default;

Fabrica::Fabrica(int cantidadPiedra, int cantidadMadera, int cantidadMetal, int maximoPermitidos) : Edificio(cantidadPiedra,cantidadMadera,cantidadMetal,maximoPermitidos){}

string Fabrica::obtenerNombreMaterialGenerable() {
    return nombreMaterialGenerable;
}
int Fabrica::obtenerCantidadMaterialGenerable() {
    return cantidadMaterialGenerable;
}
char Fabrica::obtenerNombreClave() {
    return nombreClave;
}
void Fabrica::declararPropietario(string nombreJugador){
    propietario = nombreJugador;
}
string Fabrica::obtenerPropietario() {
    return propietario;
}