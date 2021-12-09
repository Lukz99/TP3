#include "CasilleroTransitable.h"
#include "DatosLeidos.h"
#include <iostream>

using namespace std;

CasilleroTransitable::CasilleroTransitable(char terreno) : Casillero(terreno){
    setMaterial();
}

void CasilleroTransitable::setMaterial(){
    material = new Material();
}

void CasilleroTransitable::mostrar() {
    cout << getTerreno();
}

void CasilleroTransitable::modificar(char nuevoNombre) {
    terreno = nuevoNombre;
}

char CasilleroTransitable::getTerreno(){
    return terreno;
}

char CasilleroTransitable::getInicial(){
    return terrenoInicial;
}

void CasilleroTransitable::generarMaterial(string nombre,int cantidad,Casillero*** casilleros) {
    material->cargarDatos(nombre,cantidad);
    casilleros[fila][columna]->modificar(material->getNombreClave());
}
/*
void CasilleroTransitable::recolectarMaterial(Casillero*** casilleros) {
    delete material;
    casilleros[fila][columna]->modificar('C');
}*/
CasilleroTransitable::~CasilleroTransitable(){
    delete material;
}




int CasilleroTransitable::getFila() {
    return fila;
}

int CasilleroTransitable::getColumna() {
    return columna;
}

Material* CasilleroTransitable::getMaterial() {
    return material;
}

