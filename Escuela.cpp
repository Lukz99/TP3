#include "Escuela.h"

Escuela::Escuela() : Edificio(){
    nombreClave = 'E';
    nombreEdificio = "escuela";
    estadoEdificio = 1;

}

Escuela::Escuela(int cantidadPiedra, int cantidadMadera, int cantidadMetal, int maximoPermitidos) : Edificio(cantidadPiedra,cantidadMadera,cantidadMetal,maximoPermitidos){}

Escuela::~Escuela() = default;

string Escuela::obtenerNombreMaterialGenerable() {
    return nombreMaterialGenerable;
}
int Escuela::obtenerCantidadMaterialGenerable() {
    return cantidadMaterialGenerable;
}
char Escuela::obtenerNombreClave() {
    return nombreClave;
}
void Escuela::declararPropietario(string nombreJugador){
    propietario = nombreJugador;
}
string Escuela::obtenerPropietario() {
    return propietario;
}