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
        menu.mostrarMenuPrincipal();
        menu.definirOpcion();
        menu.opcionValida(5);
        menu.procesarOpcionMenuPrincipal(grafo.obtenerListaVertices(),diccionario,d1,J1,J2);
    }*/

    delete J1;
    delete J2;
}
