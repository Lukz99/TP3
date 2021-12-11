//
// Created by juamp on 4/11/2021.
//

#include "Edificio.h"
#include <iostream>
#include "CasilleroConstruible.h"

Edificio::Edificio() = default;

Edificio::~Edificio() = default;


Edificio::Edificio(int pie, int mad, int met, int max) {
    cantidadPiedra = pie;
    cantidadMadera = mad;
    cantidadMetal = met;
    maximoPermitido = max;
    setNombreClave();
}

void Edificio::declararPropietario(string nombreJugador){
    propietario = nombreJugador;
}

string Edificio::obtenerPropietario(){
    return propietario;
}

void Edificio::cargarDatos(string nom, int pie, int mad, int met, int max) {
    nombreEdificio = nom;
    cantidadPiedra = pie;
    cantidadMadera = mad;
    cantidadMetal = met;
    maximoPermitido = max;
    setNombreClave();
}

void Edificio::mostrarReceta(){
    cout << "\n" << "| Piedra: "<< cantidadPiedra << " | Madera:  " << cantidadMadera
         << " | Metal: " << cantidadMetal << " | Permitidos: " << maximoPermitido << " |" << endl;
}

void Edificio::modificarReceta(int nuevaCantPiedra,int nuevaCantMadera, int nuevaCantMetal){
    cantidadPiedra = nuevaCantPiedra;
    cantidadMadera = nuevaCantMadera;
    cantidadMetal = nuevaCantMetal;
}

void Edificio::setNombreClave(){
    nombreClave = (char)toupper(nombreEdificio[0]);
}

string Edificio::getNombre() {
    return nombreEdificio;
}

int Edificio::getPiedra(){
    return cantidadPiedra;
}
int Edificio::getMadera() {
    return cantidadMadera;
}
int Edificio::getMetal() {
    return cantidadMetal;
}
int Edificio::getMaximaCantidad(){
    return maximoPermitido;
}

char Edificio::getNombreClave() {
    return nombreClave;
}
int Edificio::getCostruidos() {
    return construidos;
}
void Edificio::mostrar_edificio() {
    cout << getNombre() << endl;
}
void Edificio::sumarEdificio(){
    construidos++;
}
void Edificio::restarEdificio(){
    construidos--;
}
void Edificio::demolicion(){
    nombreEdificio = "";
    nombreClave = ' ';
    cantidadPiedra = 0;
    cantidadMadera = 0;
    cantidadMetal = 0;
    maximoPermitido = 0;
}