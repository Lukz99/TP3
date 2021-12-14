#ifndef TP3_MENU_H
#define TP3_MENU_H
#include "CasilleroInaccesible.h"
#include "CasilleroTransitable.h"
#include "CasilleroConstruible.h"
#include "DiccionarioDeEdificios.h"
#include "Jugador.h"
#include "DatosLeidos.h"
#include "Grafo.h"

class Menu {
private:
    int opcionElegida;
public:
    Menu();
    ~Menu();

    //interfaces.
    void mostrarMenuPrincipal();
    void mostrarMenuJugador();

    //navegacion por el menu
    void definirOpcion();
    void opcionValida(int cantidadOpciones);
    int obtenerOpcion();

    //procesar opcion
    void procesarOpcionMenuJugador(Vertice* vertices, DiccionarioDeEdificios* diccionarioDeEdificios, Jugador *jugador,DatosLeidos baseDeDatos,bool &finalizarTurno);
    void procesarOpcionMenuPrincipal(Vertice* listaVertices,DiccionarioDeEdificios* diccionario,DatosLeidos baseDeDatos,Jugador *primerJugador,Jugador *segundoJugador);

    //--menu principal--
    //opcion 1
    void modificarEdificio(DiccionarioDeEdificios *diccionarioDeEdificios);
    int modificarMaterial(DiccionarioDeEdificios* diccionarioDeEdificios, string nombreMaterial, string nombreEdificio);
    //opcion 3
    void mostrarMapa(Vertice*,Casillero***,int,int);

    //--menu jugador--
    //pre-inicio
    void comenzarPartida(Vertice* listaVertices,DiccionarioDeEdificios* diccionario,DatosLeidos baseDeDatos,Jugador *primerJugador,Jugador *segundoJugador);
    void eleccionJugador(Jugador *primerJugador,Jugador *segundoJugador);
    void designarTurnos(Jugador *primerJugador,Jugador *segundoJugador);
    void lluviaRecursos(Vertice* listaVertices,DatosLeidos baseDeDatos);
    void seleccionarCoordenadasAleatoriamente(Vertice* listaVertices,string nombreMaterial,int generacionMaterial,int equivalenciaUnitaria,DatosLeidos baseDeDatos);
    void gestionDeTurnos(Vertice* vertices,DiccionarioDeEdificios* diccionarioDeEdificios,Jugador *jugadorActual,DatosLeidos baseDeDatos);

    //opcion 1
    void construirEdificio(DiccionarioDeEdificios* diccionario, Vertice* vertices, Jugador *jugador, DatosLeidos baseDeDatos);
    bool realizarDiferenciaMateriales(DiccionarioDeEdificios* diccionario, Jugador *jugador, string nombreEdificio, string nombreMaterial);
    bool materialesSuficientes(DiccionarioDeEdificios* diccionario, Jugador *jugador, string nombreEdificio);
    bool coordenadaConstruible(Vertice*, DiccionarioDeEdificios*, int, int,Jugador*, string, Casillero***);
    //opcion 3
    void demolerEdificio(Vertice*,DiccionarioDeEdificios*, Jugador*,DatosLeidos);
    void devolverMateriales(DiccionarioDeEdificios* diccionario, Jugador *jugador, string nombreEdificio);
    //opcion 4
    void atacarEdificio(Vertice* listaVertices, Jugador *jugador,DatosLeidos baseDeDatos);
    //opcion 6
    void comprarBombas(Jugador *jugador);
    //opcion 7
    void consultarCoordenada(Vertice* listaVertices, DatosLeidos baseDeDatos);
    //opcion 8
    void repararEdificio(Vertice* listaVertices,DiccionarioDeEdificios* diccionarioDeEdificios,Jugador *jugador,DatosLeidos baseDeDatos);
    //opcion 10
    void recolectarRecursos(Vertice* listaVertices,Jugador *jugador,DatosLeidos baseDeDatos);
    //opcion 12
    void guardarMapa(DatosLeidos baseDeDatos);
    void guardarUbicaciones(Vertice* listaVertices,Jugador *primerJugador,Jugador *segundoJugador,DatosLeidos baseDeDatos);
    void guardarMaterialesDelMapa(ofstream& archivoUbicaciones,Vertice* listaVertices,DatosLeidos baseDeDatos);
    void guardarEdificiosJugador(ofstream& archivoUbicaciones,Vertice* listaVertices,Jugador *jugador,DatosLeidos baseDeDatos);
    void guardarMateriales(Jugador* primerJugador,Jugador* segundoJugador );
    void extraerMaterial(ofstream& archivoMateriales,Jugador* primerJugador,Jugador* segundoJugador,string nombreMaterial);

    //funciones de uso multiple
    string validarEdificio(DiccionarioDeEdificios *diccionarioDeEdificios, string nombreEdificios);
    char realizarOperacion();
    void leerCoordenadas(int&, int&, int, int);
    void restarMateriales(DiccionarioDeEdificios* diccionario, Jugador *jugador, string nombreEdificio, double porcentajeRestable);
};


#endif //TP3_MENU_H
