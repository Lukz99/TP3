//
// Created by juamp on 4/11/2021.
//

#ifndef UNTITLED_EDIFICIO_H
#define UNTITLED_EDIFICIO_H
#include <string>

using namespace std;

class Edificio {
protected:
    string nombre = "";
    char nombreClave;
    int piedra, madera, metal, maxima_cantidad, construidosPrimerJugador = 0, construidosSegundoJugador = 0;
public:
    Edificio();
    Edificio(string,int,int,int,int);
    ~Edificio();
    void cargarDatos(string,int,int,int,int);
    void setNombreClave();
    string getNombre();
    char getNombreClave();
    int getMadera();
    int getPiedra();
    int getMetal();
    int getMaximaCantidad();
    int getCostruidos();
    void mostrar_edificio();
    void sumarEdificio();
    void restarEdificio();
    void demolicion();
};

#endif //UNTITLED_EDIFICIO_H
