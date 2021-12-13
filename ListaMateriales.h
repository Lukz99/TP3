#ifndef TP3_LISTAMATERIALES_H
#define TP3_LISTAMATERIALES_H
#include <string>
#include "NodoLista.h"

using namespace std;

class ListaMateriales {
private:
    NodoLista *nodoInicial;
public:
    ListaMateriales();
    ~ListaMateriales();
    void insertarNodo(string,int);
    void imprimirLista();
    int extraerCantidadMaterial(string nombreMaterial);
    void modificarNodo(string,int,bool);
};


#endif //TP3_LISTAMATERIALES_H
