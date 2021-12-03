#ifndef UNTITLED_MENU_H
#define UNTITLED_MENU_H
#include "CasilleroInaccesible.h"
#include "CasilleroTransitable.h"
#include "CasilleroConstruible.h"

class Menu {
private:
    int opcionElegida;
    int cantidadOpciones;
public:
    Menu(int);
    ~Menu();
    void mostrarMenuJugador();
    void mostrarMenuPrincipal();
    void setOpcion();
    void opcionValida();
    int getOpcion();
    void menuJugador(Casillero*** casilleros,int cantFilas, int cantColumnas,CasilleroConstruible** construibles, int cantidadConstruibles, CasilleroTransitable** transitables, int cantidadTransitables, Material** materiales, int cantidadMateriales, Edificio** edificios,int cantidadEdificios);
    void menuPrincipal(Casillero*** casilleros, Edificio** edificios, int cantidadEdificios, int cantFilas, int cantColumnas);

    void mostrarMapa(Casillero***,int,int);
    static void listarMateriales(Material**,int);
    static void listarEdificios(Edificio**,int);
    static void listarConstruidos(Edificio**, int);

    void recolectarRecursos(CasilleroConstruible**,int,Material**,int);

    //consultar coordenada
    void consultarCoordenada(Casillero*** casilleros,int,int, CasilleroConstruible**,int, CasilleroTransitable**,int);
    void leerCoordenadas(int&,int&,int,int);

    //lluvia
    void lluviaRecursos(CasilleroTransitable**,int,Casillero***);
    void generamientos(string,int,CasilleroTransitable**,int,Casillero***);

    //construir edificio
    void construirEdificio(CasilleroConstruible**,Casillero***,int,Material**,Edificio**, int, int, int, int);
    bool materialesSuficientes(Material**,Edificio**,int,int);
    void restarMateriales(Material**, Edificio**, int, int );

    //demoler edificio
    void demolerEdificio(Casillero***,CasilleroConstruible**,int,Material**,int,Edificio**,int,int,int);
    void devolverMateriales(Material**,int,Edificio**,int);

    //guardar y salir
    void guardarMateriales(Material**,int);
    void guardarUbicaciones(CasilleroConstruible**,int);
    void guardarMapa(Casillero***,int,int);
    void guardarEdificios(Edificio**, int);


    int posicionConstruible(int,int,CasilleroConstruible**,int);
    int posicionTransitable(int,int, CasilleroTransitable**,int);
    int buscarMaterial(string,Material**,int);
    int posicionEdificio(string, Edificio**, int );
    bool haySuperposicion(CasilleroConstruible**,int);

    void comenzarPartida();

};

template < typename Tipo >
static void listarEdificios(Edificio**,int){

}


#endif //UNTITLED_MENU_H
