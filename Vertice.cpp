#include "Vertice.h"

using namespace std;

Vertice::Vertice(char tipoTerreno, int x, int y) {
    posicionFila = x;
    posicionColumna = y;
    verticeSuperior = nullptr;
    verticeInferior = nullptr;
    verticeIzquierdo = nullptr;
    verticeDerecho = nullptr;
    tipoCasilla = tipoTerreno;

    if (tipoTerreno == 'C' || tipoTerreno == 'M' || tipoTerreno == 'B') {
        transitable = new CasilleroTransitable(tipoTerreno);
        construible = nullptr;
        inaccesible = nullptr;
    }
    else if(tipoTerreno == 'T') {
        construible = new CasilleroConstruible(tipoTerreno);
        transitable = nullptr;
        inaccesible = nullptr;
    }
    else{ // tipoTerreno == 'L'
        inaccesible = new CasilleroInaccesible(tipoTerreno);
        construible = nullptr;
        inaccesible = nullptr;
    }
}

Vertice* Vertice::buscarVerticePorPosicion(Vertice* verticeInicial,int posFila,int posColumna){
    Vertice* auxiliar = verticeInicial;
    Vertice* primerVerticeDeFila = verticeInicial;
    int contadorColumnas = 0;
    int posFil = auxiliar->obtenerPosicionFila();
    int posColu = auxiliar->obtenerPosicionColumna();
    while(posFil != posFila || posColu != posColumna){
        if(contadorColumnas == 9) {
            auxiliar = primerVerticeDeFila->verticeInferior;
            primerVerticeDeFila = auxiliar;
            contadorColumnas = 0;
        }
        else{
            contadorColumnas++;
            auxiliar = auxiliar->verticeDerecho;
        }
        posFil = auxiliar->obtenerPosicionFila();
        posColu = auxiliar->obtenerPosicionColumna();
    }
    return auxiliar;
}

bool Vertice::edificioConstruido() {
    return construible->getEdificio() != nullptr;
}
bool Vertice::materialPresente() {
    return transitable->getMaterial() != nullptr;
}

CasilleroConstruible* Vertice::obtenerCasilleroConstruible(){
    return construible;
}
CasilleroTransitable* Vertice::obtenerCasilleroTransitable() {
    return transitable;
}
CasilleroInaccesible* Vertice::obtenerCasilleroInaccesible() {
    return inaccesible;
}

void Vertice::direccionarVerticeSuperior(Vertice* verticeSuperior) {
    this->verticeSuperior = verticeSuperior;
}
void Vertice::direccionarVerticeDerecho(Vertice* verticeDerecho) {
    this->verticeDerecho = verticeDerecho;
}
void Vertice::direccionarVerticeInferior(Vertice *verticeInferior) {
    this->verticeInferior = verticeInferior;
}
void Vertice::direccionarVerticeIzquierdo(Vertice *verticeIzquierdo) {
    this->verticeIzquierdo = verticeIzquierdo;
}
int Vertice::obtenerPosicionFila(){
    return posicionFila;
}
int Vertice::obtenerPosicionColumna(){
    return posicionColumna;
}
Vertice* Vertice::obtenerVerticeDerecho() {
    return verticeDerecho;
}
Vertice* Vertice::obtenerVerticeInferior() {
    return verticeInferior;
}
Vertice* Vertice::obtenerVerticeSuperior() {
    return verticeSuperior;
}
Vertice* Vertice::obtenerVerticeIzquierdo() {
    return verticeIzquierdo;
}
char Vertice::obtenerCasilla(){
    return tipoCasilla;
}
void Vertice::construirEdificio(string nombreEdificio,Casillero*** casilleros){
    construible->construirEdificio(nombreEdificio,casilleros);
}
void Vertice::demolerEdificio(Casillero*** casilleros){
    construible->demolerEdificio(casilleros)
}