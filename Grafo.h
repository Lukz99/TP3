#ifndef TP3_GRAFO_H
#define TP3_GRAFO_H
#include "Vertice.h"
#include "Casillero.h"

class Grafo {
    // Atributos
private:
    Vertice *vertices;
    int cantidadVertices;
    int ** matrizDeCostos;

    // Metodos
public:
    Grafo();

    // Precondiciones:
    // Postcondiciones:
    void cargarListaVertices(Casillero*** casilleros, int, int);

    // Precondiciones:
    // Postcondiciones:
    void ingresarVertice(char, int, int);

    // Precondiciones:
    // Postcondiciones:
    void ingresarVerticeSuperior(Vertice*, int, int);

    // Precondiciones:
    // Postcondiciones:
    void ingresarVerticeIzquierdo(Vertice*,int,int);

    // Precondiciones:
    // Postcondiciones:
    void mostrarVertices();

    // Precondiciones:
    // Postcondiciones:
    Vertice* obtenerListaVertices();

    // Precondiciones:
    // Postcondiciones:
    void mostrarVerticesAdyacentes(int x, int y);

    // Precondiciones:
    // Postcondiciones:
    int** obtenerMatrizDeCostos();

    // Precondiciones:
    // Postcondiciones: crea la matriz de costos
    void crearMatrizDeCostos(int cantidadFilas,int cantidadColumnas,string nombreJugador);

    // Precondiciones:
    // Postcondiciones: libera la memoria de la matriz de adyacencia
    void liberarMatrizDeCostos();

    // Precondiciones:
    // Postcondiciones:
    void cargarMatrizDeCostos(int cantidadFilas, int cantidadColumnas, string nombreJugador);

    // Precondiciones:
    // Postcondiciones:
    int consultarCostoDeVertice(Vertice* verticeActual, string nombreJugador);

};

#endif //TP3_GRAFO_H
