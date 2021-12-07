#include "NodoLista.h"

NodoLista::NodoLista(string nombreMaterial, int cantidadMaterial){
    materialJugador = new Material(nombreMaterial,cantidadMaterial);
    siguiente = nullptr;
}

void NodoLista::insertarNodoSiguiente(NodoLista *nodoSiguiente){
    siguiente = nodoSiguiente;
}

Material* NodoLista::obtenerMaterial() {
    return materialJugador;
}

NodoLista* NodoLista::obtenerNodoSiguiente(){
    return siguiente;
}

NodoLista::~NodoLista(){}