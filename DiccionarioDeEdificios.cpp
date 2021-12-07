#include "DiccionarioDeEdificios.h"
#include <iostream>
#include "NodoArbol.h"

using namespace std;

ArbolDeEdificios::ArbolDeEdificios(){
    raiz = nullptr;
};

void ArbolDeEdificios::insertarNodo(NodoArbol* &arbol,string nomEdificio,int cantPiedra,int cantMadera, int cantMetal, int maxPermitido){
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

bool ArbolDeEdificios::modificarNodo(NodoArbol* arbol,string nomEdificio, int nuevaCantPiedra, int nuevaCantMadera, int nuevaCantMetal){
    if(arbol == nullptr)
        return true;

    else if(arbol->nombreEdificio == nomEdificio) {
        arbol->recetaEdificio->modificarReceta(nuevaCantPiedra,nuevaCantMadera,nuevaCantMetal);
        return false;
    }
    else if(nomEdificio[0]<arbol->nombreEdificio[0])
        return modificarNodo(arbol->izquierdo,nomEdificio,nuevaCantPiedra,nuevaCantMadera,nuevaCantMetal);
    else
        return modificarNodo(arbol->derecho,nomEdificio,nuevaCantPiedra,nuevaCantMadera,nuevaCantMetal);
}

void ArbolDeEdificios::recorridoInOrden(NodoArbol* arbol){
    if(arbol == nullptr)
        return;
    else{
        recorridoInOrden(arbol->izquierdo);
        cout << "->" << arbol->nombreEdificio;
        arbol->recetaEdificio->mostrarReceta();
        recorridoInOrden(arbol->derecho);
    }
}

void ArbolDeEdificios::mostrarArbol(NodoArbol* arbol,int contador){
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
