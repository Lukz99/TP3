#include "CasilleroConstruible.h"
#include <iostream>
#include "Aserradero.h"
#include "Escuela.h"
#include "Fabrica.h"
#include "Mina.h"
#include "MinaOro.h"
#include "PlantaElectrica.h"
#include "Obelisco.h"

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

void CasilleroConstruible::construirEdificio(string nombreEdificio, Casillero*** casilleros){
    switch (nombreEdificio[0]) {
        case 'a':
            edificiacion = new Aserradero();
            break;
        case 'e':
            edificiacion = new Escuela();
            break;
        case 'f':
            edificiacion = new Fabrica();
            break;
        case 'm':
            if (nombreEdificio == "mina oro")
                edificiacion = new MinaOro();
            else
                edificiacion = new Mina();
            break;
        case 'o':
            edificiacion = new Obelisco();
            break;
        case 'p':
            edificiacion = new PlantaElectrica();
            break;
    }
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




