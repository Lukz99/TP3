#ifndef TP3_LISTAMATERIALES_H
#define TP3_LISTAMATERIALES_H
#include <string>
#include "NodoLista.h"

using namespace std;

class ListaMateriales {
    // Atributos
private:
    NodoLista *nodoInicial;
    NodoLista *nodoUltimo;

    // Metodos
public:
    // Constructor
    ListaMateriales();

    ~ListaMateriales();

    // Precondiciones:
    // Postcondiciones: reserva memoria para un NodoLista
    void insertarNodo(string nombreMaterial, int cantidadMaterial);

    // Precondiciones:
    // Postcondiciones: imprime por pantalla la lista de materiales
    void imprimirLista();

    // Precondiciones:
    // Postcondiciones: devuelve la cantidad de material
    int extraerCantidadMaterial(string nombreMaterial);

    // Precondiciones:
    // Postcondiciones: modifica el nombre y cantidad de un material
    void modificarNodo(string nombreMaterial, int cantidad, bool realizarSuma);

    void liberarNodo();
};


#endif //TP3_LISTAMATERIALES_H
