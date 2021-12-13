#ifndef TP3_EDIFICIO_H
#define TP3_EDIFICIO_H
#include <string>

using namespace std;

class Edificio {
    // Atributos
protected:
    string nombreEdificio, propietario;
    int cantidadPiedra, cantidadMadera, cantidadMetal, maximoPermitido, construidosJugador1, construidosJugador2;
    int estadoEdificio;
    char nombreClave;
    // Metodos
public:
    Edificio();
    Edificio(int, int, int, int);
    virtual ~Edificio();
    void repararEdificio();
    void destruirEdificio();
    int obtenerEstadoEdificio();
    virtual string obtenerNombreMaterialGenerable() = 0;
    virtual int obtenerCantidadMaterialGenerable() = 0;
    virtual char obtenerNombreClave() = 0;

    //----------------------------
    // Precondiciones:
    // Postcondiciones:
    void mostrarReceta();

    // Precondiciones:
    // Postcondiciones:
    void modificarReceta(int,int,int);

    // Precondiciones:
    // Postcondiciones:
    virtual void declararPropietario(string nombreJugador) = 0;

    // Precondiciones:
    // Postcondiciones: devuelve el atributo propietario
    virtual string obtenerPropietario() = 0;
    //--------------------------------

    // Precondiciones:
    // Postcondiciones:
    void cargarDatos(string nombreEdificio, int piedra, int madera, int metal, int maximoPermitido);

    // Precondiciones:
    // Postcondiciones: devuelve el atributo nombreEdificio
    string obtenerNombre();

    // Precondiciones:
    // Postcondiciones: devuelve el atributo cantidadMadera
    int obtenerMadera();

    // Precondiciones:
    // Postcondiciones: devuelve el atributo cantidadPiedra
    int obtenerPiedra();

    // Precondiciones:
    // Postcondiciones: devuelve el atributo cantidadMetal
    int obtenerMetal();

    // Precondiciones:
    // Postcondiciones: devuelve el atributo maximoPermitido
    int obtenerMaximaCantidad();

    // Precondiciones:
    // Postcondiciones:  devuelve el atributo construidos
    int obtenerConstruidosJugador1();
    int obtenerConstruidosJugador2();

    // Precondiciones:
    // Postcondiciones:
    void mostrarEdificio();

    // Precondiciones:
    // Postcondiciones:
    void sumarEdificio(string nombreJugador);

    // Precondiciones:
    // Postcondiciones:
    void restarEdificio(string nombreJugador);
};

#endif //EDIFICIO_H
