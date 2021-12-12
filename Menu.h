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
    int cantidadOpciones;
public:
    Menu(int);
    ~Menu();

    //interfaces
    void mostrarMenuPrincipal();
    void mostrarMenuJugador();

    //navegacion por el menu
    void setOpcion();
    void opcionValida();
    int getOpcion();

    //procesar opcion
    void menuJugador(Grafo vertices, DiccionarioDeEdificios* diccionarioDeEdificios, Jugador jugador, DatosLeidos baseDeDatos);
    void menuPrincipal(DiccionarioDeEdificios* diccionario, Casillero*** casilleros, int cantFilas, int cantColumnas);

    //--menu principal--
    //opcion 1
    void modificarEdificio(DiccionarioDeEdificios *diccionarioDeEdificios);
    int modificarMaterial(DiccionarioDeEdificios* diccionarioDeEdificios, string nombreMaterial, string nombreEdificio);
    //opcion 3
    void mostrarMapa(Casillero***,int,int);

    //--menu jugador--
    //opcion 1
    void construirEdificio(DiccionarioDeEdificios* diccionario, Grafo vertices, Jugador jugador, DatosLeidos baseDeDatos);
    bool realizarDiferenciaMateriales(DiccionarioDeEdificios* diccionario, Jugador jugador, string nombreEdificio, string nombreMaterial);
    bool materialesSuficientes(DiccionarioDeEdificios* diccionario, Jugador jugador, string nombreEdificio);
    bool coordenadaConstruible(Vertice*, DiccionarioDeEdificios*, int, int, Jugador, string, Casillero***);
    //opcion 3
    void demolerEdificio(Vertice*,DiccionarioDeEdificios*, Jugador,DatosLeidos);
    void devolverMateriales(DiccionarioDeEdificios* diccionario, Jugador jugador, string nombreEdificio);
    //opcion 4
    void atacarEdificio(Vertice* listaVertices, Jugador jugador,DatosLeidos baseDeDatos);
    //opcion 6
    void comprarBombas(Jugador jugador);
    //opcion 7
    void consultarCoordenada(Vertice* listaVertices, DatosLeidos baseDeDatos);
    //opcion 8
    void repararEdificio(Vertice* listaVertices,DiccionarioDeEdificios* diccionarioDeEdificios,Jugador jugador,DatosLeidos baseDeDatos);
    //opcion 10
    void recolectarRecursos(Vertice* listaVertices,Jugador jugador,DatosLeidos baseDeDatos);

    //funciones de uso multiple
    string validarEdificio(DiccionarioDeEdificios *diccionarioDeEdificios, string nombreEdificios);
    string realizarOperacion();
    void leerCoordenadas(int&, int&, int, int);
    void restarMateriales(DiccionarioDeEdificios* diccionario, Jugador jugador, string nombreEdificio, double porcentajeRestable);

    //opciones de menu jugador sin readaptar
    void recolectarRecursos(CasilleroConstruible**, int, Material**,int);
    void lluviaRecursos(CasilleroTransitable**, int, Casillero***);
    void generamientos(string, int, CasilleroTransitable**, int, Casillero***);
    void guardarMateriales(Material**, int);
    void guardarUbicaciones(CasilleroConstruible**, int);
    void guardarMapa(Casillero***, int, int);
    void guardarEdificios(Edificio**, int);

    //opciones posiblemente descartables
    bool haySuperposicion(CasilleroConstruible**, int);
};


#endif //TP3_MENU_H
