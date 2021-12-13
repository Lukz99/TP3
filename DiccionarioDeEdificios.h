#ifndef TP3_DICCIONARIODEEDIFICIOS_H
#define TP3_DICCIONARIODEEDIFICIOS_H
#include "NodoArbol.h"
#include <string>

using namespace std;

class NodoArbol;

class DiccionarioDeEdificios {
    // Atributos
private:
    NodoArbol* raiz;
    void insertarNodo(NodoArbol *&arbol, string nombreEdificio, int cantidadPiedra, int cantidadMadera, int cantidadMetal, int maximoPermitido);

    // Metodos
public:
    // Constructor
    DiccionarioDeEdificios();

    // Precondiciones:
    // Postcondiciones: complemento de insertar un nodo al diccionario de edificios
    void procesarDatoANodo(string nombreEdificio, int cantidadPiedra, int cantidadMadera, int cantidadMetal, int maximoPermitido);

    // Precondiciones:
    // Postcondiciones: imprime por pantalla el diccionario como un arbol
    void mostrarArbol(NodoArbol*, int);

    // Precondiciones:
    // Postcondiciones: devuelve false si no se encuentra en el diccionario, true en caso de que sí
    bool nodoEnArbol(NodoArbol* arbol, string nombreEdificio);

    // Precondiciones:
    // Postcondiciones:
    bool modificarNodo(NodoArbol*, string, int, int, int);
    int extraerDato(NodoArbol*, string, string);
    void recorridoInOrden(NodoArbol*);
    void listarConstruidos(NodoArbol* arbol,string nombreJugador);
    void modificacionEnConstruidos(NodoArbol* arbol,string nombreJugador,string nombreEdificio, bool realizarSuma);
    NodoArbol* obtenerNodoRaiz();
    void guardarDatosDiccionario(NodoArbol*);
};

#endif //TP3_DICCIONARIODEEDIFICIOS_H
