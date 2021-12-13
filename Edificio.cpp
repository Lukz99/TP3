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
}

void Edificio::declararPropietario(string nombreJugador){
    propietario = nombreJugador;
}

void Edificio::repararEdificio() {
    if (estadoEdificio == 2)
        cout << "El edificio ingresado se encuentra en perfecto estado." << endl;
    else if (estadoEdificio == 1) {
        estadoEdificio++;
        cout << "Edificio reparado correctamente." << endl;
    } else
        cout << "No puede reparar este edificio porque ya ha sido completamente destruido." << endl;
}

void Edificio::destruirEdificio() {
    if (estadoEdificio == 2) {
        estadoEdificio--;
        cout << "Edificio parcialmente dañado." << endl;
    } else if (estadoEdificio == 1) {
        estadoEdificio--;
        cout << "Edificio completamente destruido." << endl;
    } else
        cout << "Este edificio ya ha sido destruido." << endl;
}

int Edificio::obtenerEstadoEdificio() {
    return estadoEdificio;
}



string Edificio::obtenerPropietario() {
    return propietario;
}

void Edificio::cargarDatos(string nom, int pie, int mad, int met, int max) {
    nombreEdificio = nom;
    cantidadPiedra = pie;
    cantidadMadera = mad;
    cantidadMetal = met;
    maximoPermitido = max;
}

void Edificio::mostrarReceta() {
    cout << "\n" << "| Piedra: "<< cantidadPiedra << " | Madera:  " << cantidadMadera
         << " | Metal: " << cantidadMetal << " | Permitidos: " << maximoPermitido << " |" << endl;
}

void Edificio::modificarReceta(int nuevaCantPiedra,int nuevaCantMadera, int nuevaCantMetal) {
    cantidadPiedra = nuevaCantPiedra;
    cantidadMadera = nuevaCantMadera;
    cantidadMetal = nuevaCantMetal;
}

string Edificio::obtenerNombre() {
    return nombreEdificio;
}

int Edificio::obtenerPiedra() {
    return cantidadPiedra;
}
int Edificio::obtenerMadera() {
    return cantidadMadera;
}
int Edificio::obtenerMetal() {
    return cantidadMetal;
}
int Edificio::obtenerMaximaCantidad() {
    return maximoPermitido;
}

int Edificio::obtenerConstruidos() {
    return construidos;
}
void Edificio::mostrarEdificio() {
    cout << obtenerNombre() << endl;
}
void Edificio::sumarEdificio() {
    construidos++;
}
void Edificio::restarEdificio() {
    construidos--;
}
