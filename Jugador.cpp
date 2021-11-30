//
// Created by juamp on 30/11/2021.
//

#include "Jugador.h"

Jugador::Jugador(int numeroJugador) {
    if (numeroTurno == 1)
        nombreJugador = "Jugador 1";
    else
        nombreJugador = "Jugador 2";
}

Jugador::~Jugador() = default;

void Jugador::restaurarEnergia() {
    energia += 20;
}

int Jugador::obtenerEnergia() {
    return energia;
}