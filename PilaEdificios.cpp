//
// Created by ekizu on 3/12/2021.
//

#include "PilaEdificios.h"

PilaEdificios::PilaEdificios() {
    nodoInicial = nullptr;
}

void PilaEdificios::insertarNodo(string nombreMaterial,int cantidadMaterial){
    NodoPila *nodoNuevo = new NodoPila(nombreMaterial,cantidadMaterial);
    nodoNuevo->insertarNodoSiguiente(nodoInicial);
    nodoInicial = nodoNuevo;
}

void PilaEdificios::imprimirPila(){
    NodoPila *nodoEnRecorrido = nodoInicial;
    while(nodoEnRecorrido != nullptr) {
        nodoEnRecorrido->obtenerMaterial()->mostrarMaterial();
        nodoEnRecorrido = nodoEnRecorrido->obtenerNodoSiguiente();
    }
}

void PilaEdificios::modificarNodo(string nombreMaterial,int cantidadOperativa, bool realizarSuma){
    bool nodoEncontrado = false;
    NodoPila* nodoEnRecorrido = nodoInicial;
    while(nodoEnRecorrido != nullptr || !nodoEncontrado){
        if(nodoEnRecorrido->obtenerMaterial()->obtenerNombre() == nombreMaterial){
            if (realizarSuma)
                nodoEnRecorrido->obtenerMaterial()->sumar(cantidadOperativa);
            else
                nodoEnRecorrido->obtenerMaterial()->restar(cantidadOperativa);
            nodoEncontrado = true;
        }
        nodoEnRecorrido = nodoEnRecorrido->obtenerNodoSiguiente();
    }
}

PilaEdificios::~PilaEdificios() {}