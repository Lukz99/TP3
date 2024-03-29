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

int ListaMateriales::extraerCantidadMaterial(string nombreMaterial){
    bool nodoEncontrado = false;
    NodoLista *nodoEnRecorrido = nodoInicial;
    int cantidadMaterialBuscado;
    while(nodoEnRecorrido != nullptr && !nodoEncontrado){
        if(nodoEnRecorrido->obtenerMaterial()->obtenerNombre() == nombreMaterial){
            cantidadMaterialBuscado = nodoEnRecorrido->obtenerMaterial()->obtenerCantidad();
            nodoEncontrado = true;
        }
        else
            nodoEnRecorrido = nodoEnRecorrido->obtenerNodoSiguiente();
    }
    return cantidadMaterialBuscado;
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

void ListaMateriales::liberarNodo() {
    NodoLista* auxiliar;


}

ListaMateriales::~ListaMateriales() {}
