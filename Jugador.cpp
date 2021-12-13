#include "Jugador.h"
#include "ListaMateriales.h"

Jugador::Jugador() {
    objetivosJugador = nullptr;
    listaMateriales = new ListaMateriales();
    energia = 50;
}

void Jugador::asignarNombre(string nombreElegido){
    nombreJugador = nombreElegido;
}

void Jugador::asignarTurno(int numeroDeTurno){
    ordenDeTurno = numeroDeTurno;
}

Jugador::~Jugador() {
    delete [] objetivosJugador;
}

string Jugador::obtenerNombreJugador() {
    return nombreJugador;
}

void Jugador::cargarMaterial(string nombreMaterial, int cantidadMaterial) {
    listaMateriales -> insertarNodo(nombreMaterial, cantidadMaterial);
}

void Jugador::recibirMatrizDeCostos(int **matrizDeCostos) {
    matrizDeCostosJugador = matrizDeCostos;
}

void Jugador::mostrarMateriales() {
    listaMateriales -> imprimirLista();
}

ListaMateriales* Jugador::obtenerListaMateriales() {
    return listaMateriales;
}


void Jugador::sumarEnergia(int sumando) {
    if(energia + sumando > 100)
        sumando = energia - sumando;
    energia += sumando;
}

void Jugador::restarEnergia(int restando) {
    if (energia - restando < 0)
        restando = restando - energia;
    energia -= restando;
}


int Jugador::obtenerEnergia() {
    return energia;
}

bool Jugador::jugadorSinEnergias(){
    return energia = 0;
}