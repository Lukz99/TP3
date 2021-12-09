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
    void ingresarArista(Vertice*,Vertice*,int);
    void mostrarVertices();
    Vertice* getVertice(char);
    void mostrarVerticesAdyacentes(int x, int y);

    //Precondiciones:
    //Postcondiciones: crea la matriz de costos
    void crearMatrizDeCostos();

    //post: libera la memoria de la matriz de adyacencia
    void liberarMatrizDeCostos();

    void definirCostos(string nombreJugador);

    int consultaCosto(Vertice* verticeActual, string nombreJugador);

};

#endif //TP3_GRAFO_H
