#include "ListaMateriales.h"

ListaMateriales::ListaMateriales() {
    nodoInicial = nullptr;
}

void ListaMateriales::insertarNodo(string nombreMaterial,int cantidadMaterial){
    NodoLista *nodoNuevo = new NodoLista(nombreMaterial,cantidadMaterial);
    nodoNuevo->insertarNodoSiguiente(nodoInicial);
    nodoInicial = nodoNuevo;
}

void ListaMateriales::imprimirLista(){
    NodoLista *nodoEnRecorrido = nodoInicial;
    while(nodoEnRecorrido != nullptr) {
        nodoEnRecorrido->obtenerMaterial()->mostrarMaterial();
        nodoEnRecorrido = nodoEnRecorrido->obtenerNodoSiguiente();
    }
}

void ListaMateriales::modificarNodo(string nombreMaterial,int cantidadOperativa, bool realizarSuma){
    bool nodoEncontrado = false;
    NodoLista* nodoEnRecorrido = nodoInicial;
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

ListaMateriales::~ListaMateriales(){}