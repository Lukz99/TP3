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
    // Constructor
    Grafo();

    // Precondiciones:
    // Postcondiciones: carga los vertices en la matriz casilleros
    void cargarListaVertices(Casillero*** casilleros, int filas, int columnas);

    // Precondiciones:
    // Postcondiciones: reserva memoria para un vertice y define sus vertices adyacentes
    void ingresarVertice(char tipoTerreno, int x, int y);

    // Precondiciones:
    // Postcondiciones: define el vertice superior un vertice por caso excepcional
    void ingresarVerticeSuperior(Vertice* verticeActual, int x , int y);

    // Precondiciones:
    // Postcondiciones:
    void ingresarVerticeIzquierdo(Vertice*,int,int);

    // Precondiciones:
    // Postcondiciones:
    void mostrarVertices();

    // Precondiciones:
    // Postcondiciones: devuelve la lista de vertices
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
    // Postcondiciones: define el costo de un movimiento en una matriz
    void cargarMatrizDeCostos(int cantidadFilas, int cantidadColumnas, string nombreJugador);

    // Precondiciones:
    // Postcondiciones: devuelve el costo de moverse a verticeActual
    int consultarCostoDeVertice(Vertice* verticeActual, string nombreJugador);

};

#endif //TP3_GRAFO_H
