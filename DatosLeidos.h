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

    void cargarListaMateriales(ifstream& archivoMateriales,Jugador primerJugador,Jugador segundoJugador);
    void cargarDiccionarioDeEdificios(ifstream& archivoEdificios,DiccionarioDeEdificios *diccionarioPartida);

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

    //PRE: -
    //POS: Lee los edificios a construir y las carga al casillero construible que corresponda segun coordenadas
    void registrarUbicaciones(ifstream&);

public:
    //Constructor sin parametros
    DatosLeidos();
    //Destructor
    ~DatosLeidos();

    //PRE: Recibe el nombre de un archivo
    //POS: Lo abre y llama a la funcion designada para cada tipo de archivo
    void leerArchivo(string nombreArchivo,Jugador primerJugador,Jugador segundoJugador,DiccionarioDeEdificios *diccionarioPartida );

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
};

#endif //UNTITLED_DATOSLEIDOS_H

