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

void Edificio::repararEdificio() {
    if (estadoEdificio == 2)
        cout << "El edificio ingresado se encuentra en perfecto estado, no es necesaria una reparacion." << endl;
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

int Edificio::obtenerConstruidosJugador1() {
    return construidosJugador1;
}
int Edificio::obtenerConstruidosJugador2(){
    return construidosJugador2;
}
void Edificio::mostrarEdificio() {
    cout << obtenerNombre() << endl;
}
void Edificio::sumarEdificio(string nombreJugador) {
    if(nombreJugador == "Jugador 1")
        construidosJugador1++;
    else
        construidosJugador2++;
}
void Edificio::restarEdificio(string nombreJugador) {
    if(nombreJugador == "Jugador 1")
        construidosJugador1--;
    else
        construidosJugador2--;
}
