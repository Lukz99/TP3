#include "DiccionarioDeEdificios.h"
#include <iostream>
#include "NodoArbol.h"
#include "fstream"

using namespace std;

DiccionarioDeEdificios::DiccionarioDeEdificios(){
    raiz = nullptr;
};

void DiccionarioDeEdificios::procesarDatoANodo(string nombreEdificio, int cantidadPiedra,int cantidadMadera, int cantidadMetal, int maximoPermitido) {
    insertarNodo(raiz,nombreEdificio,cantidadPiedra,cantidadMadera,cantidadMetal,maximoPermitido);
}

void DiccionarioDeEdificios::insertarNodo(NodoArbol* &arbol,string nomEdificio,int cantPiedra,int cantMadera, int cantMetal, int maxPermitido){
    if(arbol == nullptr) {
        NodoArbol *nodoNuevo = new NodoArbol(nomEdificio, cantPiedra, cantMadera, cantMetal, maxPermitido);
        arbol = nodoNuevo;
    }
    else {
        char clave = arbol->nombreEdificio[0];
        if (nomEdificio[0] < clave)
            insertarNodo(arbol->izquierdo, nomEdificio, cantPiedra, cantMadera, cantMetal, maxPermitido);
        else {
            insertarNodo(arbol->derecho, nomEdificio,cantPiedra,cantMadera,cantMetal,maxPermitido);
        }
    }
}

bool DiccionarioDeEdificios::nodoEnArbol(NodoArbol* arbol,string nomEdificio){
    if(arbol == nullptr)
        return false;
    else if(arbol->nombreEdificio == nomEdificio)
        return true;
    else if(nomEdificio[0]<arbol->nombreEdificio[0])
        return nodoEnArbol(arbol->izquierdo,nomEdificio);
    else
        return nodoEnArbol(arbol->derecho,nomEdificio);
}

bool DiccionarioDeEdificios::modificarNodo(NodoArbol* arbol,string nomEdificio, int nuevaCantPiedra, int nuevaCantMadera, int nuevaCantMetal){
    if(arbol->nombreEdificio == nomEdificio) {
        arbol->recetaEdificio->modificarReceta(nuevaCantPiedra,nuevaCantMadera,nuevaCantMetal);
    }
    else if(nomEdificio[0]<arbol->nombreEdificio[0])
        modificarNodo(arbol->izquierdo,nomEdificio,nuevaCantPiedra,nuevaCantMadera,nuevaCantMetal);
    else
        modificarNodo(arbol->derecho,nomEdificio,nuevaCantPiedra,nuevaCantMadera,nuevaCantMetal);
}

int DiccionarioDeEdificios::extraerDato(NodoArbol* arbol,string nombreEdificio,string nombreDato) {
    if (arbol->nombreEdificio == nombreEdificio) {
        if (nombreDato == "piedra")
            arbol->recetaEdificio->getPiedra();
        else if (nombreDato == "madera")
            arbol->recetaEdificio->getMadera();
        else if (nombreDato == "metal")
            arbol->recetaEdificio->getMetal();
        else if (nombreDato == "maximo permitido")
            arbol->recetaEdificio->getMaximaCantidad();
        else
            arbol->recetaEdificio->getCostruidos();
    }
    else if (nombreEdificio[0] < arbol->nombreEdificio[0])
        return extraerDato(arbol->izquierdo,nombreEdificio,nombreDato);
    else
        return extraerDato(arbol->derecho, nombreEdificio, nombreDato);
}

void DiccionarioDeEdificios::recorridoInOrden(NodoArbol* arbol){
    if(arbol == nullptr)
        return;
    else{
        recorridoInOrden(arbol->izquierdo);
        cout << "->" << arbol->nombreEdificio;
        arbol->recetaEdificio->mostrarReceta();
        recorridoInOrden(arbol->derecho);
    }
}

void DiccionarioDeEdificios::listarConstruidos(NodoArbol* arbol){
    if(arbol == nullptr)
        return;
    else{
        listarConstruidos(arbol->izquierdo);
        if (arbol->obtenerReceta()->getCostruidos() > 0)
            cout << "->" << arbol->nombreEdificio << "\nConstruidos: " << arbol->obtenerReceta()->getCostruidos()
                 << endl;
        listarConstruidos(arbol->derecho);
    }
}

void DiccionarioDeEdificios::modificacionEnConstruidos(NodoArbol* arbol, string nombreEdificio, bool realizarSuma){
    if (arbol->nombreEdificio == nombreEdificio) {
       if (realizarSuma)
           arbol->recetaEdificio->sumarEdificio();
       else
           arbol->recetaEdificio->restarEdificio();
    }
    else if (nombreEdificio[0] < arbol->nombreEdificio[0])
        return modificacionEnConstruidos(arbol->izquierdo,nombreEdificio, realizarSuma);
    else
        return modificacionEnConstruidos(arbol->derecho, nombreEdificio, realizarSuma);
}

void DiccionarioDeEdificios::guardarDatosDiccionario(NodoArbol* arbol) {
    ofstream nuevoArchivoEdificios("edificios.txt");
    Edificio* recetaActual;
    if(arbol == nullptr)
        return;
    else{
        guardarDatosDiccionario(arbol->izquierdo);
        recetaActual = arbol->recetaEdificio;
        nuevoArchivoEdificios << arbol->nombreEdificio << " " << recetaActual->getNombre() << " "
                              << recetaActual->getPiedra() << " " << recetaActual->getMadera() << " "
                              << recetaActual->getMetal() << " " << recetaActual->getMaximaCantidad() << endl;
        guardarDatosDiccionario(arbol->derecho);
    }
}



void DiccionarioDeEdificios::mostrarArbol(NodoArbol* arbol,int contador){
    if(arbol == nullptr)
        return;
    else{
        mostrarArbol(arbol->derecho,contador+1);
        for (int i=0;i<contador;i++)
            cout << "    ";
        cout << arbol->nombreEdificio[0] << endl;
        mostrarArbol(arbol->izquierdo,contador+1);
    }
}

NodoArbol* DiccionarioDeEdificios::obtenerNodoRaiz(){
    return raiz;
}