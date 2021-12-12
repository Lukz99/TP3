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

void CasilleroTransitable::generarMaterial(string nombre, int cantidadMaterial, Casillero*** casilleros) {
    material = new Material(nombre, cantidadMaterial);
    casilleros[fila][columna] -> modificar(material -> getNombreClave());
}

void CasilleroTransitable::recolectarMaterial(Casillero*** casilleros) {
    delete material;
    material = nullptr;
    casilleros[fila][columna] -> modificar('C');
}

CasilleroTransitable::~CasilleroTransitable() {
    delete material;
}




int CasilleroTransitable::obtenerFila() {
    return fila;
}

int CasilleroTransitable::obtenerColumna() {
    return columna;
}

Material* CasilleroTransitable::obtenerMaterial() {
    return material;
}

