#ifndef NODOARBOL_H
#define NODOARBOL_H
#include <string>
#include "Edificio.h"

using namespace std;

class NodoArbol {
public:
    //atributos
    string nombreEdificio;
    Edificio* recetaEdificio;
    NodoArbol* derecho;
    NodoArbol* izquierdo;
    //metodos
    NodoArbol(string,int,int,int,int);
    void cargarReceta(int,int,int,int);
    Edificio* obtenerReceta();
    ~NodoArbol();
};


#endif //NODOARBOL_H
