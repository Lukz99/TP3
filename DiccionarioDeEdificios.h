#ifndef TP3_DICCIONARIODEEDIFICIOS_H
#define TP3_DICCIONARIODEEDIFICIOS_H
#include "NodoArbol.h"
#include <string>

using namespace std;

class NodoArbol;

class DiccionarioDeEdificios {
private:
    NodoArbol* raiz;
    void insertarNodo(NodoArbol *&arbol, string nombreEdificio, int cantidadPiedra, int cantidadMadera, int cantidadMetal, int maximoPermitido);
public:
    DiccionarioDeEdificios();
    void procesarDatoANodo(string nombreEdificio, int cantidadPiedra, int cantidadMadera, int cantidadMetal, int maximoPermitido);
    void mostrarArbol(NodoArbol*,int);
    bool nodoEnArbol(NodoArbol*, string);
    bool modificarNodo(NodoArbol*, string, int, int, int);
    int extraerDato(NodoArbol*, string, string);
    void recorridoInOrden(NodoArbol*);
    void listarConstruidos(NodoArbol* arbol,string nombreJugador);
    void modificacionEnConstruidos(NodoArbol* arbol,string nombreJugador,string nombreEdificio, bool realizarSuma);
    NodoArbol* obtenerNodoRaiz();
    void guardarDatosDiccionario(NodoArbol*);
};

#endif //TP3_DICCIONARIODEEDIFICIOS_H
