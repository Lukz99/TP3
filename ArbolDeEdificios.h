#ifndef DICCIONARIODEEDIFICIOS_H
#define DICCIONARIODEEDIFICIOS_H
#include "NodoArbol.h"
#include <string>

using namespace std;

class DiccionarioDeEdificios {
public:
    //atributo
    NodoArbol* raiz;
    //metodos
    ArbolDeEdificios();
    void insertarNodo(NodoArbol*&,string,int,int,int,int);
    void mostrarArbol(NodoArbol*,int);
    bool nodoEnArbol(NodoArbol*,string);
    bool modificarNodo(NodoArbol*,string,int,int,int);
    int extraerMaterial(NodoArbol*,string,string);
    void recorridoInOrden(NodoArbol*);
};

#endif //DICCIONARIODEEDIFICIOS_H
