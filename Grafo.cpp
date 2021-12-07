#include "Grafo.h"

/*
 if(tipoTerreno = 'C'){
    CasilleroTransitable* casillero = new CasilleroTransitable(tipoTerreno,x,y);
    Vertice<CasilleroTransitable> *nuevoVertice = new Vertice(casillero);
 */
void Grafo::leerMapa(Casillero* mapa){
    for (int i=0; i<cantidadFilas,i++)
        for (int j=0; j<cantidadColumnas,j++)
            ingresarVertice(mapa[i][j]->getTerreno,i,j);
            int verticeSuperior = i - 1;
            int verticeDerecho = j + 1;
            int verticeInferior = i + 1;
            int verticeIzquierdo = j - 1;

}

void Grafo::ingresarVertice(char tipoTerreno,int x,int y) {
    Vertice *nuevoVertice = new Vertice(tipoTerreno,x,y);
    if(vertices == nullptr)
        vertices = nuevoVertice;
    else{
        Vertice* auxiliar = vertices;
        while (auxiliar->siguiente != nullptr)
            auxiliar = vertices->siguiente;
        auxiliar->siguiente = nuevoVertice;
    }
    //agrandarMatrizDeAdyacencia();
}