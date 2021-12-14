#ifndef INC_3MOSQUETEROS_NODOPILA_H
#define INC_3MOSQUETEROS_NODOPILA_H
#include "Material.h"

class NodoLista {
private:
    Material* materialJugador;
    NodoLista* siguiente;
public:
    NodoLista(string nombreMaterial, int cantidadMaterial);
    ~NodoLista();
    void insertarNodoSiguiente(NodoLista*);
    Material* obtenerMaterial();
    NodoLista* obtenerNodoSiguiente();
};


#endif //INC_3MOSQUETEROS_NODOPILA_H
