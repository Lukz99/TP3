//
// Created by ekizu on 3/12/2021.
//

#ifndef INC_3MOSQUETEROS_LISTAMATERIALES_H
#define INC_3MOSQUETEROS_LISTAMATERIALES_H
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
    void modificarNodo(string,int,bool);
};


#endif //INC_3MOSQUETEROS_LISTAMATERIALES_H
