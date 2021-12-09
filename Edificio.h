#ifndef EDIFICIO_H
#define EDIFICIO_H
#include <string>

using namespace std;

class Edificio {
protected:
    string nombre = "";
    char nombreClave;
    int cantidadPiedra, cantidadMadera, cantidadMetal, maximoPermitido, construidos = 0;
public:
    Edificio();
    Edificio(int,int,int,int);
    ~Edificio();

    //_---------------------------
    void mostrarReceta();
    void modificarReceta(int,int,int);
    //--------------------------------
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

#endif //EDIFICIO_H
