#include <iostream>
#include "Material.h"
#include "DatosLeidos.h"
#include "Menu.h"
#include "DiccionarioDeEdificios.h"
#include "ListaMateriales.h"
#include "Jugador.h"
#include "Grafo.h"
#include "Objetivos.h"


using namespace std;

int main() {
    Jugador *J1 = new Jugador;
    Jugador *J2 = new Jugador;

    /*Objetivos O1;
    O1.asignarObjetivo();
    O1.mostrarObjetivos();
    O1.confirmarObjetivos(1, J1);
    O1.confirmarObjetivos(2, J1);
    O1.confirmarObjetivos(3, J1);*/

    DatosLeidos d1;
    Grafo grafo;
    Menu menu;

    DiccionarioDeEdificios* diccionario = new DiccionarioDeEdificios();
    d1.crearMapa();
    d1.cargarDiccionarioDeEdificios(diccionario);
    d1.cargarListaMateriales(J1,J2);

    grafo.cargarListaVertices(d1.obtenerCasilleros(),d1.obtenerCantidadFilas(),d1.obtenerCantidadColumnas());
    d1.registrarUbicaciones(grafo.obtenerListaVertices(),diccionario);
/*
    while(menu.obtenerOpcion() != 4 && menu.obtenerOpcion() != 5) {
        menu.mostrarMenuJugador();
        menu.definirOpcion();
        menu.opcionValida(5);
        menu.procesarOpcionMenuJugador(grafo.obtenerListaVertices(), diccionario, d1,J1,J2);
    }*/
    system("pause");
    menu.eleccionJugador(J1,J2);
    menu.gestionDeTurnos(grafo,diccionario,J1,d1);


/*
    while(opcion != 11){
        menu.procesarOpcion(d1.getCasilleros(), d1.getCantidadFilas(), d1.getCantidadColumnas(), d1.getConstruibles(), d1.cantConstruibles(), d1.getTransitables(), d1.cantTransitables(), d1.getMateriales(), d1.getCantidadMateriales(), d1.getEdficios(), d1.getCantidadEdificios());
        menu.mostrarMenu();
        menu.setOpcion();
        menu.opcionValida();
        opcion = menu.getOpcion();
    }*/
    //grafo.crearMatrizDeCostos(d1.obtenerCantidadFilas(),d1.obtenerCantidadColumnas(),J1.obtenerNombreJugador());
    //J1.recibirMatrizDeCostos(grafo.obtenerMatrizDeCostos());
    //grafo.crearMatrizDeCostos(d1.getCantidadFilas(),d1.getCantidadColumnas(),J2.obtenerNombreJugador());
    //J2.recibirMatrizDeCostos(grafo.obtenerMatrizDeCostos());
    delete J1;
    delete J2;
}
