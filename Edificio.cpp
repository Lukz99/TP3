//
// Created by juamp on 4/11/2021.
//

#include "Edificio.h"
#include <iostream>
#include "CasilleroConstruible.h"

Edificio::Edificio() = default;

Edificio::~Edificio() = default;

Edificio::Edificio(string nom, int pie, int mad, int met, int max) {
    nombre = nom;
    piedra = pie;
    madera = mad;
    metal = met;
    maxima_cantidad = max;
    setNombreClave();
}

void Edificio::cargarDatos(string nom, int pie, int mad, int met, int max) {
    nombre = nom;
    piedra = pie;
    madera = mad;
    metal = met;
    maxima_cantidad = max;
    setNombreClave();
}

void Edificio::setNombreClave(){
    nombreClave = (char)toupper(nombre[0]);
}

string Edificio::getNombre() {
    return nombre;
}
char Edificio::getNombreClave() {
    return nombreClave;
}
int Edificio::getMadera(){
    return madera;
}
int Edificio::getPiedra(){
    return piedra;
}
int Edificio::getMetal(){
    return metal;
}
int Edificio::getMaximaCantidad(){
    return maxima_cantidad;
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
    nombre = "";
    nombreClave = ' ';
    piedra = 0;
    madera = 0;
    metal = 0;
    maxima_cantidad = 0;
}