#ifndef TP3_GRAFO_H
#define TP3_GRAFO_H
#include "Vertice.h"
#include "Casillero.h"

class Grafo {
private:
    Vertice *vertices;
    int cantidadVertices;
    int ** matrizDeCostos;
public:
    Grafo();
    void cargarListaVertices(Casillero*** casilleros,int,int);
    void ingresarVertice(char,int,int);
    void ingresarVerticeSuperior(Vertice*,int,int);
    void ingresarVerticeIzquierdo(Vertice*,int,int);
    void mostrarVertices();
    Vertice* obtenerListaVertices();
    void mostrarVerticesAdyacentes(int x, int y);
    int** obtenerMatrizDeCostos();

    //Precondiciones:
    //Postcondiciones: crea la matriz de costos
    void crearMatrizDeCostos(int cantidadFilas,int cantidadColumnas,string nombreJugador);

    //post: libera la memoria de la matriz de adyacencia
    void liberarMatrizDeCostos();

    void cargarMatrizDeCostos(int cantidadFilas, int cantidadColumnas, string nombreJugador);

    int consultarCostoDeVertice(Vertice* verticeActual, string nombreJugador);

};

#endif //TP3_GRAFO_H
