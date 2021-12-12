#ifndef NODOARBOL_H
#define NODOARBOL_H
#include <string>
#include "Edificio.h"
#include "DiccionarioDeEdificios.h"

using namespace std;

class NodoArbol {
    friend class DiccionarioDeEdificios;

    // Atributos
private:
    string nombreEdificio;
    Edificio* recetaEdificio;
    NodoArbol* derecho;
    NodoArbol* izquierdo;
public:
    NodoArbol();
    NodoArbol(string nombre, int piedra, int madera, int metal, int permitidos);
    void cargarReceta(int piedra, int madera, int metal, int permitidos);
    string obtenerNombreEdificio();
    Edificio* obtenerReceta();
    NodoArbol* obtenerNodoDerecho();
    NodoArbol* obtenerNodoIzquierdo();
    ~NodoArbol();
};


#endif //NODOARBOL_H
