#include "Grafo.h"

#include <iostream>

using namespace std;

Grafo::Grafo() {
    vertices = nullptr;
    matrizDeAdyacencia = nullptr;
    cantidadVertices = 0;
}

void Grafo::cargarListaVertices(Casillero*** casilleros,int filas,int columnas){
    for (int i=0;i<filas;i++)
        for (int j=0;j<columnas;j++) {
            ingresarVertice(casilleros[i][j]->getTerreno(), i, j);
            cout << i << " " << j << endl;
        }
}

void Grafo::ingresarVertice(char tipoTerreno,int x,int y) {
    Vertice *nuevoVertice = new Vertice(tipoTerreno,x,y);
    Vertice * auxiliar;
    Vertice* anterior;
    if (vertices == nullptr)
        vertices = nuevoVertice;
    else {
        if (y == 0) {//es decir, reinicia el conteo de columnas
            //busca el vertice parado en la misma columna pero de la fila de arriba
            auxiliar = vertices->buscarVerticePorPosicion(vertices, x - 1, 0);
            //direcciona su vertice inferior al actual
            auxiliar->direccionarVerticeInferior(nuevoVertice);
            nuevoVertice->direccionarVerticeSuperior(auxiliar);
        } else{
            //busca vertice anterior al actual
            anterior = vertices->buscarVerticePorPosicion(vertices, x, y - 1);
            //hace que el vertice derecho del anterior apunte al actual
            anterior->direccionarVerticeDerecho(nuevoVertice);
            //busca el vertice actual
            auxiliar = vertices->buscarVerticePorPosicion(vertices, x, y);
            //direcciona su vertice izquierdo con el vertice anterior
            auxiliar->direccionarVerticeIzquierdo(anterior);
            if (x > 0)
                ingresarVerticeSuperior(auxiliar, x, y);
        }
    }
}

void Grafo::ingresarVerticeSuperior(Vertice* verticeActual,int x, int y){
    Vertice* verticeSuperior = vertices->buscarVerticePorPosicion(vertices,x-1,y);
    verticeActual->direccionarVerticeSuperior(verticeSuperior);
    verticeSuperior->direccionarVerticeInferior(verticeActual);
}

void Grafo::mostrarVertices() {
    Vertice *auxiliar;
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 10; j++) {
            auxiliar = vertices->buscarVerticePorPosicion(vertices, i, j);
            char tipoTerreno = auxiliar->obtenerCasilla();
            cout << tipoTerreno << " ";
            if (j == 9)
                cout << "\n";
        }
}

void Grafo::mostrarVerticesAdyacentes(int x, int y){
    Vertice* verticeBuscado = vertices->buscarVerticePorPosicion(vertices,x,y);
    cout << "        " << verticeBuscado->obtenerVerticeSuperior()->obtenerCasilla() << endl
         << "\n  " << verticeBuscado->obtenerVerticeIzquierdo()->obtenerCasilla() << "     " <<
         verticeBuscado->obtenerCasilla() << "     " << verticeBuscado->obtenerVerticeDerecho()->obtenerCasilla() << endl
         << "\n        " << verticeBuscado->obtenerVerticeInferior()->obtenerCasilla() << endl;

}