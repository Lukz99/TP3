#include "NodoArbol.h"
#include "Aserradero.h"
#include "Escuela.h"
#include "Fabrica.h"
#include "Mina.h"
#include "MinaOro.h"
#include "Obelisco.h"
#include "PlantaElectrica.h"

NodoArbol::NodoArbol(){}

NodoArbol::NodoArbol(string nombre, int piedra, int madera, int metal, int permitidos) {
    nombreEdificio = nombre;
    derecho = nullptr;
    izquierdo = nullptr;
    cargarReceta(piedra, madera, metal, permitidos);
}

void NodoArbol::cargarReceta(int piedra, int madera, int metal, int permitidos) {
    switch (nombreEdificio[0]) {
        case 'a':
            recetaEdificio = new Aserradero(piedra, madera, metal, permitidos);
            break;
        case 'e':
            recetaEdificio = new Escuela(piedra, madera, metal, permitidos);
            break;
        case 'f':
            recetaEdificio = new Fabrica(piedra, madera, metal, permitidos);
            break;
        case 'm':
            if (nombreEdificio == "mina oro")
                recetaEdificio = new MinaOro(piedra, madera, metal, permitidos);
            else
                recetaEdificio = new Mina(piedra, madera, metal, permitidos);
            break;
        case 'o':
            recetaEdificio = new Obelisco(piedra, madera, metal, permitidos);
            break;
        case 'p':
            recetaEdificio = new PlantaElectrica(piedra, madera, metal, permitidos);
            break;
    }
}
string NodoArbol::obtenerNombreEdificio(){
    return nombreEdificio;
}
Edificio* NodoArbol::obtenerReceta() {
    return recetaEdificio;
}
NodoArbol* NodoArbol::obtenerNodoDerecho(){
    return derecho;
}
NodoArbol* NodoArbol::obtenerNodoIzquierdo(){
    return izquierdo;
}

NodoArbol::~NodoArbol(){}
