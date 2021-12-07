#include <iostream>
#include "Material.h"
#include "DatosLeidos.h"
#include "Menu.h"
#include "DiccionarioDeEdificios.h"
#include "ListaMateriales.h"
#include "Jugador.h"

using namespace std;

int main() {
    int contador = 0;

    //----------------------PRUEBA ARBOL----------------------
    /*
    DiccionarioDeEdificios A;
    A.procesarDatoANodo("aserradero", 100, 32, 31, 2);
    A.procesarDatoANodo("escuela", 32, 12, 31, 5);
    A.recorridoInOrden(A.obtenerNodoRaiz());
    A.mostrarArbol(A.obtenerNodoRaiz(), contador);
    */
    //------------------PRUEBA LISTA MATERIALES-----------------
    /*DatosLeidos d1;
    Jugador J1;
    Jugador J2;

    d1.leerArchivo("materiales.txt",J1,J2);
    J1.mostrarMateriales();
    cout << "-----------------" << endl;
    J2.mostrarMateriales();
*/
    //------------------PRUEBA LECTURA DE EDIFICIOS---------------
/*    DatosLeidos d1;
    Jugador J1;
    Jugador J2;
    DiccionarioDeEdificios* diccionario = new DiccionarioDeEdificios();
    d1.leerArchivo("edificios.txt",J1,J2, diccionario);
    diccionario->mostrarArbol(diccionario->obtenerNodoRaiz(),contador);
    diccionario->recorridoInOrden(diccionario->obtenerNodoRaiz());
*/

    DatosLeidos d1;
    Jugador J1;
    Jugador J2;
    DiccionarioDeEdificios* diccionario = new DiccionarioDeEdificios();

    d1.leerArchivo("mapa.txt",J1,J2,diccionario);
    cout << "aaa" << endl;
    for ( int i=0;i<d1.cantInaccesibles();i++)
        cout << d1.getInaccesibles()[i]->getTerreno() << endl;

    /*

    Menu m(9);

    system("pause");
    m.modificarEdificio(A);
    A.recorridoInOrden(A.raiz);


    DatosLeidos d1;

    d1.leerArchivo("mapa.txt");
    d1.leerArchivo("materiales.txt");
    d1.leerArchivo("edificios.txt");
    d1.leerArchivo("ubicaciones.txt");

    Menu menu(11);

    int opcion = 0;

    menu.mostrarMenuPrincipal();
    menu.setOpcion();
    menu.opcionValida();
    opcion = menu.getOpcion();

    while(opcion != 11){
        menu.procesarOpcion(d1.getCasilleros(), d1.getCantidadFilas(), d1.getCantidadColumnas(), d1.getConstruibles(), d1.cantConstruibles(), d1.getTransitables(), d1.cantTransitables(), d1.getMateriales(), d1.getCantidadMateriales(), d1.getEdficios(), d1.getCantidadEdificios());
        menu.mostrarMenu();
        menu.setOpcion();
        menu.opcionValida();
        opcion = menu.getOpcion();
    }*/
}
