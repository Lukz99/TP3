//
// Created by ekizu on 3/12/2021.
//

#include "NodoPila.h"

NodoPila::NodoPila(string nombreMaterial, int cantidadMaterial){
    materialJugador = new Material(nombreMaterial,cantidadMaterial);
    siguiente = nullptr;
}

void NodoPila::insertarNodoSiguiente(NodoPila *nodoSiguiente){
    siguiente = nodoSiguiente;
}

Material* NodoPila::obtenerMaterial() {
    return materialJugador;
}

NodoPila* NodoPila::obtenerNodoSiguiente(){
    return siguiente;
}

NodoPila::~NodoPila(){}