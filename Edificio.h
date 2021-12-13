#ifndef TP3_EDIFICIO_H
#define TP3_EDIFICIO_H
#include <string>

using namespace std;

class Edificio {
    // Atributos
protected:
    string nombreEdificio, propietario;
    int cantidadPiedra, cantidadMadera, cantidadMetal, maximoPermitido, construidos = 0;
    int estadoEdificio;
    char nombreClave;
    // Metodos
public:
    Edificio();
    Edificio(int, int, int, int);
    ~Edificio();
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
    void declararPropietario(string nombreJugador);

    // Precondiciones:
    // Postcondiciones: devuelve el atributo propietario
    string obtenerPropietario();
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
    int obtenerConstruidos();

    // Precondiciones:
    // Postcondiciones:
    void mostrarEdificio();

    // Precondiciones:
    // Postcondiciones:
    void sumarEdificio();

    // Precondiciones:
    // Postcondiciones:
    void restarEdificio();

    // Precondiciones:
    // Postcondiciones:
    void demolicion();
};

#endif //EDIFICIO_H
