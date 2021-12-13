#include "PlantaElectrica.h"

PlantaElectrica::PlantaElectrica() : Edificio(){
    nombreClave = 'P';
    nombreEdificio = "Planta electrica";
}
PlantaElectrica::~PlantaElectrica() = default;

PlantaElectrica::PlantaElectrica(int cantidadPiedra, int cantidadMadera, int cantidadMetal, int maximoPermitidos) : Edificio(cantidadPiedra,cantidadMadera,cantidadMetal,maximoPermitidos){}

string PlantaElectrica::obtenerNombreMaterialGenerable() {
    return nombreMaterialGenerable;
}
int PlantaElectrica::obtenerCantidadMaterialGenerable() {
    return cantidadMaterialGenerable;
}
char PlantaElectrica::obtenerNombreClave() {
    return nombreClave;
}
void PlantaElectrica::declararPropietario(string nombreJugador){
    propietario = nombreJugador;
}
string PlantaElectrica::obtenerPropietario() {
    return propietario;
}