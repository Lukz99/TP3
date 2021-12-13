#include "CasilleroTransitable.h"
#include "DatosLeidos.h"
#include <iostream>

using namespace std;

CasilleroTransitable::CasilleroTransitable(char terreno) : Casillero(terreno) {
    material = nullptr;
}

void CasilleroTransitable::mostrar() {
    cout << obtenerTerreno();
}

void CasilleroTransitable::modificar(char nuevoNombre) {
    terreno = nuevoNombre;
}

char CasilleroTransitable::obtenerTerreno() {
    return terreno;
}

char CasilleroTransitable::obtenerInicial() {
    return terrenoInicial;
}

void CasilleroTransitable::generarMaterial(string nombre, int cantidadMaterial, Casillero*** casilleros, int posicionX, int posicionY) {
    material = new Material(nombre, cantidadMaterial);
    //casilleros[posicionX][posicionY] -> modificar(material->obtenerNombreClave());
}

void CasilleroTransitable::recolectarMaterial(Casillero*** casilleros) {
    delete [] material;
    material = nullptr;
    //casilleros[fila][columna] -> modificar('C');
}

CasilleroTransitable::~CasilleroTransitable() {
    if(material != nullptr)
        delete [] material;
}

Material* CasilleroTransitable::obtenerMaterial() {
    return material;
}

bool CasilleroTransitable::materialPresente(){
    return material != nullptr;
}

