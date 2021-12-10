#include "Jugador.h"
#include "ListaMateriales.h"

Jugador::Jugador(int numeroJugador) {
    if (numeroJugador == 1)
        nombreJugador = "Jugador 1";
    else
        nombreJugador = "Jugador 2";
}

Jugador::Jugador(){
    listaMateriales = new ListaMateriales();
};

Jugador::~Jugador(){};

string Jugador::obtenerNombreJugador(){
    return nombreJugador;
}

void Jugador::cargarMaterial(string nombreMaterial, int cantidadMaterial) {
    listaMateriales->insertarNodo(nombreMaterial,cantidadMaterial);
}

void Jugador::recibirMatrizDeCostos(int **matrizDeCostos) {
    matrizDeCostosJugador = matrizDeCostos;
}

void Jugador::mostrarMateriales(){
    listaMateriales->imprimirLista();
}

void Jugador::restaurarEnergia() {
    energia += 20;
}

int Jugador::obtenerEnergia() {
    return energia;
}