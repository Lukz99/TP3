#ifndef TP3_DATOSLEIDOS_H
#define TP3_DATOSLEIDOS_H
#include <string>
#include "Edificio.h"
#include "Material.h"
#include "CasilleroConstruible.h"
#include "CasilleroTransitable.h"
#include "CasilleroInaccesible.h"
#include "Jugador.h"
#include "DiccionarioDeEdificios.h"
#include "Vertice.h"

using namespace std;

class DatosLeidos {
private:
    // Atributos

    //->Matriz polimorfica
    Casillero ***casilleros;
    int cantidadFilas, cantidadColumnas;

    //->Arreglos de casilleros
    CasilleroConstruible **construibles;
    CasilleroTransitable **transitables;
    CasilleroInaccesible **inaccesibles;
    int cantidadConstruibles = 0, cantidadTransitables = 0, cantidadInaccesibles = 0;

    // Metodos


    // Precondiciones: -
    // Postcondiciones: Carga los atributos fila y columna con las dimensiones que llevara el mapa
    void definirDimensiones(ifstream &);

    // Precondiciones: Toma las dimensiones de la matriz
    // Postcondiciones: Reserva memoria para la matriz dinamica
    void generarMapa();

    // Precondiciones: -
    // Postcondiciones: Carga el mapa con cada tipo de casillero según el dato leido
    void definirMapa(ifstream&);

    // Precondiciones:
    // Postcondiciones:
    bool aperturaDeArchivoExitosa(ifstream& archivo, string nombreArchivo);

public:
    //Constructor sin parametros
    DatosLeidos();

    //Destructor
    ~DatosLeidos();

    //Getters

    Casillero*** obtenerCasilleros();
    int obtenerCantidadFilas();
    int obtenerCantidadColumnas();

    CasilleroConstruible** obtenerConstruibles();
    CasilleroTransitable** obtenerTransitables();
    CasilleroInaccesible** obtenerInaccesibles();

    int cantConstruibles();
    int cantTransitables();
    int cantInaccesibles();

    // Precondiciones: -
    // Postcondiciones: Lee los edificios a construir y las carga al casillero construible que corresponda segun las coordenadas
    void registrarUbicaciones(Vertice* listaVertices, DiccionarioDeEdificios* diccionarioDeEdificios);
    void generarMaterialesEnMapa(ifstream &archivoUbicaciones, Vertice* listaVertices, Vertice* verticeEnPosicionActual, string coordenadaX, string coordenadaY);
    void generarEdificiosJugador(ifstream &archivoUbicaciones, DiccionarioDeEdificios* diccionario, Vertice* listaVertices, Vertice* verticeEnPosicionActual, string coordenadaX, string coordenadaY);

    // Precondiciones:
    // Postcondiciones:
    void cargarListaMateriales(Jugador *primerJugador, Jugador *segundoJugador);

    // Precondiciones:
    // Postcondiciones:
    void cargarDiccionarioDeEdificios(DiccionarioDeEdificios *diccionarioPartida);

    // Precondiciones:
    // Postcondiciones:
    void crearMapa();

};

#endif //TP3_DATOSLEIDOS_H

