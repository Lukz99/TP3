#include <iostream>
#include "Material.h"
#include "DatosLeidos.h"
#include "Menu.h"
#include "DiccionarioDeEdificios.h"
#include "ListaMateriales.h"
#include "Jugador.h"

using namespace std;

int main() {

    DatosLeidos d1;
    Jugador J1;
    Jugador J2;

    d1.leerArchivo("materiales.txt",J1,J2);
    J1.mostrarMateriales();
    cout << "-----------------" << endl;
    J2.mostrarMateriales();

    /*cout << "holis" << endl;

    ArbolDeEdificios A;

    A.insertarNodo(A.raiz,"escuela",20,10,50,21);
    A.insertarNodo(A.raiz,"obelisco",200,100,500,1);

    A.recorridoInOrden(A.raiz);

    int y = 0;

    A.mostrarArbol(A.raiz,y);
    cout << "---------------------------------" << endl;

    A.modificarNodo(A.raiz, "obelisco", 100, 20, 1);

    A.recorridoInOrden(A.raiz);

    cout << "---------------------------------" << endl;

    ListaMateriales *P = new ListaMateriales();

    P->insertarNodo("madera", 23);
    P->insertarNodo("piedra", 12);
    P->modificarNodo("piedra", 10, false);
    P->imprimirLista();

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
