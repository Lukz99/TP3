//
// Created by juamp on 30/11/2021.
//

#include "Jugador.h"

Jugador::Jugador(int numeroTurno) {
    if (numeroTurno == 1)
        nombreJugador = 'J';
    else
        nombreJugador = 'U';
}

Jugador::~Jugador() = default;

void Jugador::restaurarEnergia() {
    energia += 20;
}

int Jugador::obtenerEnergia() {
    return energia;
}