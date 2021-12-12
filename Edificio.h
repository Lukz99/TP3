#ifndef TP3_EDIFICIO_H
#define TP3_EDIFICIO_H
#include <string>

using namespace std;

class Edificio {
    // Atributos
protected:
    string nombreEdificio, propietario;
    char nombreClave;
    int cantidadPiedra, cantidadMadera, cantidadMetal, maximoPermitido, construidos = 0;
    int estadoEdificio;

    // Metodos
public:
    Edificio();
    Edificio(int, int, int, int);
    ~Edificio();
    void repararEdificio();
    void destruirEdificio();
    int obtenerEstadoEdificio();
    virtual string obtenerNombreMaterialProducible();
    virtual int obtenerCantidadMaterialProducible();

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
    // Postcondiciones:
    void definirNombreClave();

    // Precondiciones:
    // Postcondiciones: devuelve el atributo nombreEdificio
    string obtenerNombre();

    // Precondiciones:
    // Postcondiciones: devuelve el atributo nombreClave
    char obtenerNombreClave();

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
    void mostrar_edificio();

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
