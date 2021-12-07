#ifndef UNTITLED_DATOSLEIDOS_H
#define UNTITLED_DATOSLEIDOS_H
#include <string>
#include "Edificio.h"
#include "Material.h"
#include "CasilleroConstruible.h"
#include "CasilleroTransitable.h"
#include "CasilleroInaccesible.h"
#include "Jugador.h"

using namespace std;

class DatosLeidos {
private:
    //ATRIBUTOS

    //->Materiales y edificios
    Material **materiales;
    Edificio **edificios;
    int cantidadMateriales = 0, cantidadEdificios = 0;

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
    //POS: Lee materiales.txt y carga sus datos
    void setMateriales(ifstream&);

    void cargarListaMateriales(ifstream& archivoMateriales,Jugador primerJugador,Jugador segundoJugador);

    //PRE: Recibe los datos que se van extrayendo del txt
    //POS: Redimensiona el arreglo de materiales leidos para ir añadiendo datos nuevos
    void cargarMateriales(string,int);

    //PRE: -
    //POS: Lee edificios.txt y carga sus datos
    void setEdificios(ifstream &);

    //PRE: Recibe los datos que se van extrayendo del txt
    //POS: Redimensiona el arreglo de edficios leidos para ir añadiendo datos nuevos
    void cargarEdificios(string,int,int,int,int);

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

    //PRE: Recibe el nombre de un edificio
    //POS: Devuelve su posicion en el arreglo de edificios para asi extrar sus datos, de lo contrario devuelve -1
    int posicionEdificio(string);

    //PRE: Recibe las coordenadas de un edificio
    //POS: Devuelve la posicion del casillero construible que cumpla con dichos datos, de lo contrario devuelve -1
    int posicionConstruible(int, int);

    //PRE: -
    //POS: Verifica si hay un edificio construido en el casillero
    bool haySuperposicion(int);

public:
    //Constructor sin parametros
    DatosLeidos();
    //Destructor
    ~DatosLeidos();

    //PRE: Recibe el nombre de un archivo
    //POS: Lo abre y llama a la funcion designada para cada tipo de archivo
    void leerArchivo(string nombreArchivo,Jugador primerJugador,Jugador segundoJugador );

    //Getters
    Edificio** getEdficios();
    Material** getMateriales();
    int getCantidadEdificios();
    int getCantidadMateriales();

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

