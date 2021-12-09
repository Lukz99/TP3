#include "CasilleroConstruible.h"
#include <iostream>

using namespace std;

CasilleroConstruible::CasilleroConstruible(char terreno) : Casillero(terreno){
    edificiacion = nullptr;
}

CasilleroConstruible::~CasilleroConstruible(){
    delete edificiacion;
}

void CasilleroConstruible::modificar(char nuevoNombre) {
    terreno = nuevoNombre;
}

char CasilleroConstruible::getTerreno(){
    return terreno;
}

char CasilleroConstruible::getInicial(){
    return terrenoInicial;
}


void CasilleroConstruible::mostrar() {
    cout << getTerreno();
}
/*
void CasilleroConstruible::construirEdificio(string nombre, int piedra, int madera, int metal, int maximo, Casillero*** casilleros) {
    edificiacion->cargarDatos(nombre,piedra,madera,metal,maximo);
    casilleros[fila][columna]->modificar(edificiacion->getNombreClave());
}

void CasilleroConstruible::demolerEdificio(Casillero*** casilleros){
    edificiacion->demolicion();
    casilleros[fila][columna]->modificar('T');
}

int CasilleroConstruible::getFila() {
    return fila;
}

int CasilleroConstruible::getColumna() {
    return columna;
}*/
Edificio* CasilleroConstruible::getEdificio() {
    return edificiacion;
}




