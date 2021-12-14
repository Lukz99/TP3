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
    // Atributos
private:
    int opcionElegida;

    // Metodos
public:
    // Constructor
    Menu();

    ~Menu();

    // Interfaces
    // Precondiciones:
    // Postcondiciones: imprime por pantalla el menú principal
    void mostrarMenuPrincipal();

    // Precondiciones:
    // Postcondiciones: imprime por pantalla el menú de acciones de juego
    void mostrarMenuJugador();

    // Navegacion por el menu

    // Precondiciones:
    // Postcondiciones: pide al usuario que ingrese una opcion
    void definirOpcion();

    // Precondiciones:
    // Postcondiciones: revisa si la opcion ingresada es valida, si no, vuelve a pedir el ingreso de una opcion
    void opcionValida(int cantidadOpciones);

    // Precondiciones:
    // Postcondiciones: devuelve la opcion ingresada
    int obtenerOpcion();

    // Precondiciones:
    // Postcondiciones: llama al metodo que corresponde segun la opcion ingresada, en el menu de juego
    void procesarOpcionMenuJugador(Vertice* vertices, DiccionarioDeEdificios* diccionarioDeEdificios, Jugador *jugador, DatosLeidos baseDeDatos,bool &finalizarTurno);

    // Precondiciones:
    // Postcondiciones: llama al metodo que corresponde segun la opcion ingresada, en el menu principal
    void procesarOpcionMenuPrincipal(Vertice* listaVertices,DiccionarioDeEdificios* diccionario,DatosLeidos baseDeDatos,Jugador *primerJugador,Jugador *segundoJugador);

    // Menu principal
    // Opcion 1
    // Precondiciones:
    // Postcondiciones: modifica los requisitos de construccion de un edificio
    void modificarEdificio(DiccionarioDeEdificios *diccionarioDeEdificios);

    // Precondiciones:
    // Postcondiciones: modifica la cantidad de material para construir un edificio
    int modificarMaterial(DiccionarioDeEdificios* diccionarioDeEdificios, string nombreMaterial, string nombreEdificio);

    //Opcion 3
    // Precondiciones:
    // Postcondiciones: Imprime por pantalla el mapa de terrenos y el de edificios
    void mostrarMapa(Vertice*,Casillero***,int,int);

    // Menu jugador
    // Pre-inicio
    void comenzarPartida(Vertice* listaVertices,DiccionarioDeEdificios* diccionario,DatosLeidos baseDeDatos,Jugador *primerJugador,Jugador *segundoJugador) ;
    void eleccionJugador(Jugador *primerJugador,Jugador *segundoJugador);
    void designarTurnos(Jugador *primerJugador,Jugador *segundoJugador);

    // Precondiciones:
    // Postcondiciones: imprime por pantalla de quien es el turno
    void gestionDeTurnos(Vertice* vertices,DiccionarioDeEdificios* diccionarioDeEdificios,Jugador *jugadorActual,DatosLeidos baseDeDatos);
    void lluviaRecursos(Vertice* listaVertices,DatosLeidos baseDeDatos);
    void seleccionarCoordenadasAleatoriamente(Vertice* listaVertices,string nombreMaterial,int generacionMaterial,int equivalenciaUnitaria,DatosLeidos baseDeDatos);
    
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