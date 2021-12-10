#ifndef UNTITLED_DATOSLEIDOS_H
#define UNTITLED_DATOSLEIDOS_H
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
    //ATRIBUTOS

    //->Matriz polimorfica
    Casillero ***casilleros;
    int cantidadFilas, cantidadColumnas;

    //->Arreglos de casilleros
    CasilleroConstruible **construibles;
    CasilleroTransitable **transitables;
    CasilleroInaccesible **inaccesibles;
    int cantidadConstruibles = 0, cantidadTransitables = 0, cantidadInaccesibles = 0;

    //METODOS


    //PRE: -
    //POS: Carga atributos fila y columna con las dimensiones que llevara el mapa
    void setDimensiones(ifstream &);

    //PRE: Toma las dimensiones de la matriz
    //POS: Reserva memoria para la matriz dinamica
    void generarMapa();

    //PRE: -
    //POS: Carga el mapa con cada tipo de casillero según el dato leido
    void setMapa(ifstream&);

    //PRE: -
    //POS: Separa cada tipo de casillero en tres arreglos, de manera que el programa pueda acceder a sus metodos
    void separarCasilleros();

    bool aperturaDeArchivoExitosa(ifstream& archivo,string nombreArchivo);

public:
    //Constructor sin parametros
    DatosLeidos();
    //Destructor
    ~DatosLeidos();

    //Getters

    Casillero*** getCasilleros();
    int getCantidadFilas();
    int getCantidadColumnas();

    CasilleroConstruible** getConstruibles();
    CasilleroTransitable** getTransitables();
    CasilleroInaccesible** getInaccesibles();

    int cantConstruibles();
    int cantTransitables();
    int cantInaccesibles();

    //PRE: -
    //POS: Lee los edificios a construir y las carga al casillero construible que corresponda segun coordenadas
    void registrarUbicaciones(Vertice*);
    void cargarListaMateriales(Jugador primerJugador,Jugador segundoJugador);
    void cargarDiccionarioDeEdificios(DiccionarioDeEdificios *diccionarioPartida);
    void crearMapa();

};

#endif //UNTITLED_DATOSLEIDOS_H

