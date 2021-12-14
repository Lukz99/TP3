#include "Jugador.h"
#include "ListaMateriales.h"

Jugador::Jugador() {
    //objetivosJugador = nullptr;
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
    delete listaMateriales;
    //delete [] objetivosJugador;
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

int Jugador::obtenerTurno() {
    return ordenDeTurno;
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
/*
void Jugador::cargarPosicion(int x, int y){
    posicionX = x;
    posicionY = y;
}

int Jugador::obtenerPosicionX(){
    return posicionX;
}

int Jugador::obtenerPosicionY(){
    return posicionY;
}
*/

int Jugador::obtenerEnergia() {
    return energia;
}

bool Jugador::suficienteEnergia(int cantidadRequerida){
    return energia >= cantidadRequerida;
}

bool Jugador::jugadorSinEnergias(){
    return energia == 0;
}

int Jugador::obtenerPosicionX() {
    return posicionX;
}

int Jugador::obtenerPosicionY() {
    return posicionY;
}