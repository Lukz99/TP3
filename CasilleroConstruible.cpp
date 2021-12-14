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
    if(edificiacion != nullptr)
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

void CasilleroConstruible::construirEdificio(string nombreEdificio, Casillero*** casilleros, int coordenadaX, int coordenadaY){
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
    casilleros[coordenadaX][coordenadaY] -> modificar(edificiacion -> obtenerNombreClave());
}

void CasilleroConstruible::demolerEdificio(Casillero*** casilleros) {
    delete edificiacion;
    edificiacion = nullptr;
}

void CasilleroConstruible::edificiosReparables(bool repararEdificio, Casillero*** casilleros) {
    if (repararEdificio)
        edificiacion -> repararEdificio();
    else {
        edificiacion -> destruirEdificio();
        if (edificiacion -> obtenerEstadoEdificio() == 0)
            demolerEdificio(casilleros);
    }
}

Edificio* CasilleroConstruible::obtenerEdificio() {
    return edificiacion;
}

bool CasilleroConstruible::edificioConstruido(){
    return edificiacion != nullptr;
}


