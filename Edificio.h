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
    // Constructor sin parametros
    Edificio();
    // Constructor con parametros
    Edificio(int cantidadPiedra, int cantidadMadera, int cantidadMetal, int maximoPermitido);

    virtual ~Edificio() = 0;

    // Precondiciones:
    // Postcondiciones: de ser posible, se repara el edificio
    void repararEdificio();

    // Precondiciones:
    // Postcondiciones: se daña al edificio
    void destruirEdificio();

    // Precondiciones:
    // Postcondiciones: devuelve el estado del edificio (sano devuelve 2, dañado devuelve 1, destruido devuelve 0)
    int obtenerEstadoEdificio();

    // Precondiciones:
    // Postcondiciones: devuelve el material que produce el edificio
    virtual string obtenerNombreMaterialGenerable() = 0;

    // Precondiciones:
    // Postcondiciones: devuelve la cantidad de material que produce el edificio
    virtual int obtenerCantidadMaterialGenerable() = 0;

    // Precondiciones:
    // Postcondiciones: devuelve el atributo nombreClave del edificio
    virtual char obtenerNombreClave() = 0;

    // Precondiciones:
    // Postcondiciones: imprime por pantalla los materiales necesarios para construir un edificio, y la cantidad maxima que se permiten construir
    void mostrarReceta();

    // Precondiciones:
    // Postcondiciones: modifica los materiales necesarios para construir un edificio
    void modificarReceta(int cantidadPiedra, int cantidadMadera, int cantidadMetal);

    // Precondiciones:
    // Postcondiciones: establece el "dueño" de un edificio
    virtual void declararPropietario(string nombreJugador) = 0;

    // Precondiciones:
    // Postcondiciones: devuelve el atributo propietario
    virtual string obtenerPropietario() = 0;

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
    // Postcondiciones:  devuelve el atributo construidos del jugador 1
    int obtenerConstruidosJugador1();

    // Precondiciones:
    // Postcondiciones:  devuelve el atributo construidos del jugador 2
    int obtenerConstruidosJugador2();

    // Precondiciones:
    // Postcondiciones:
    void mostrarEdificio();

    // Precondiciones:
    // Postcondiciones: incrementa en 1 la cantidad de edificios de un jugador
    void sumarEdificio(string nombreJugador);

    // Precondiciones:
    // Postcondiciones: decrementa en 1 la cantidad de edificios de un jugador
    void restarEdificio(string nombreJugador);
};

#endif //TP3_EDIFICIO_H
