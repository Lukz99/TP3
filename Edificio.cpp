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

void Edificio::cargarDatos(string nom, int pie, int mad, int met, int max) {
    nombre = nom;
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
    nombreClave = (char)toupper(nombre[0]);
}

string Edificio::getNombre() {
    return nombre;
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
    nombre = "";
    nombreClave = ' ';
    cantidadPiedra = 0;
    cantidadMadera = 0;
    cantidadMetal = 0;
    maximoPermitido = 0;
}