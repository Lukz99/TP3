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

CasilleroConstruible::CasilleroConstruible(char terreno) : Casillero(terreno) {
    edificiacion = nullptr;
}

CasilleroConstruible::~CasilleroConstruible() {
    delete edificiacion;
}

void CasilleroConstruible::modificar(char nuevoNombre) {
    terreno = nuevoNombre;
}

char CasilleroConstruible::obtenerTerreno() {
    return terreno;
}

char CasilleroConstruible::obtenerInicial() {
    return terrenoInicial;
}


void CasilleroConstruible::mostrar() {
    cout << obtenerTerreno();
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

void CasilleroConstruible::demolerEdificio(Casillero*** casilleros){
    delete [] edificiacion;
    edificiacion = nullptr;
}
/*
int CasilleroConstruible::getFila() {
    return fila;
}

int CasilleroConstruible::getColumna() {
    return columna;
}*/
Edificio* CasilleroConstruible::obtenerEdificio() {
    return edificiacion;
}




