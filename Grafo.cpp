#include "Grafo.h"

#include <iostream>

using namespace std;

Grafo::Grafo() {
    vertices = nullptr;
    matrizDeCostos = nullptr;
    cantidadVertices = 0;
}

//liberarMatrizDeCostos();


void Grafo::crearMatrizDeCostos() {

    matrizDeCostos = new int* [8];
    for(int i = 0; i < 8; i++) {
        matrizDeCostos[i] = new int[10];
    }
    //inicializarNuevoVertice(matrizAuxiliar);
}



void Grafo::definirCostos(string nombreJugador) {
    Vertice *verticeActual;
    int costoMovilizacion;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 10; j++) {
            verticeActual = vertices->buscarVerticePorPosicion(vertices, i, j);
            costoMovilizacion = consultaCosto(verticeActual, nombreJugador);
            matrizDeCostos[i][j] = costoMovilizacion;
        }
    }
    for (int i= 0; i< 8; i++){
        for (int j=0; j<10;j++)
            cout << matrizDeCostos[i][j] << " ";
        cout << "\n";
    }
}
/*
        int origenver = origen . obtenerPosi
        int posicionOrigen = vertices ->obtenerPosicion(origen);
        int posicionDestino = vertices ->obtenerPosicion(destino);

        if(posicionOrigen == POSICION_NO_ENCONTRADA){
            cout << "El vertice " << origen << " no existe en el grafo" << endl;
        }
        if(posicionDestino == POSICION_NO_ENCONTRADA){
            cout << "El vertice " << destino << " no existe en el grafo" << endl;
        }

        if(!(posicionDestino == POSICION_NO_ENCONTRADA || posicionOrigen == POSICION_NO_ENCONTRADA)) {
            matrizDeAdyacencia[posicionOrigen][posicionDestino] = peso;
            matrizDeAdyacencia[posicionDestino][posicionOrigen] = peso;
        }

    }

    }
    */


int Grafo::consultaCosto(Vertice* actual, string nombreJugador) {
    char tipoTerrenoDestino = actual->obtenerCasilla();
    int costoCamino;
    switch (tipoTerrenoDestino){
        case 'B':
            costoCamino = 0;
            break;
        case 'C':
            costoCamino = 4;
            break;
        case 'T':
            if (actual->edificioConstruido())
                costoCamino = 25;
            break;
        case 'L':
            if (nombreJugador == "Jugador 1")
                costoCamino = 2;
            else
                costoCamino = 5;
            break;
        case 'M':
            if (nombreJugador == "Jugador 1")
                costoCamino = 5;
            else
                costoCamino = 2;
            break;
    }
    return costoCamino;

}


void Grafo::cargarListaVertices(Casillero*** casilleros, int filas, int columnas){
    for (int i=0;i<filas;i++)
        for (int j=0;j<columnas;j++) {
            ingresarVertice(casilleros[i][j]->getTerreno(), i, j);
            cantidadVertices++;
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
        } else {
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

void Grafo::liberarMatrizDeCostos() {
    for(int i = 0; i < cantidadVertices; i++){
        delete[] matrizDeCostos[i];
    }
    delete[] matrizDeCostos;
}