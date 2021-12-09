#ifndef TP3_GRAFO_H
#define TP3_GRAFO_H
#include "Vertice.h"
#include "Casillero.h"

class Grafo {
private:
    Vertice *vertices;
    int cantidadVertices;
    int ** matrizDeAdyacencia;
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
};

#endif //TP3_GRAFO_H
