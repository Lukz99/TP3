#ifndef TP3_JUGADOR_H
#define TP3_JUGADOR_H
#include <string>
#include "Material.h"
#include "ListaMateriales.h"
#include "Objetivos.h"

using namespace std;

class Jugador {
    // Atributos
private:
    string nombreJugador;
    int ordenDeTurno;
    ListaMateriales* listaMateriales;
    int** matrizDeCostosJugador;
    //Objetivos* objetivosJugador;
    int energia;
    int posicionX, posicionY;

    // Metodos
public:
    // Constructor sin parametros
    Jugador();

    // Constructor con parametro
    Jugador(int);

    ~Jugador();

    // Precondiciones:
    // Postcondiciones: agrega el material y su cantidad a una lista de materiales
    void cargarMaterial(string nombreMaterial, int cantidadMaterial);

    void recibirMatrizDeCostos(int** matrizDeCostos);

    // Precondiciones:
    // Postcondiciones: imprime por pantalla la lista de materiales
    void mostrarMateriales();

    // Precondiciones:
    // Postcondiciones: devuelve true si la energia para realizar la accion es suficiente, de lo contrario devuelve false
    bool suficienteEnergia(int cantidadRequerida);

    // Precondiciones:
    // Postcondiciones: define el numero de turno de un jugador
    void asignarTurno(int numeroDeTurno);

    // Precondiciones:
    // Postcondiciones: devuelve el atributo listaMateriales
    ListaMateriales* obtenerListaMateriales();

    // Precondiciones:
    // Postcondiciones: establece el nombre del jugador
    void asignarNombre(string nombreElegido);

    // Precondiciones:
    // Postcondiciones: devuelve el nombre del jugador
    string obtenerNombreJugador();

    // Precondiciones:
    // Postcondiciones: resta energia al jugador
    void restarEnergia(int cantidadEnergia);

    // Precondiciones:
    // Postcondiciones: suma energia al jugador
    void sumarEnergia(int cantidadEnergia);

    // Precondiciones:
    // Postcondiciones: devuelve el valor del atributo energia
    int obtenerEnergia();

    // Precondiciones:
    // Postcondiciones: devuelve true si se cumplio el objetivo principal, de lo contrario false
    bool objetivoPrincipalCumplido();

    // Precondiciones:
    // Postcondiciones: devuelve true si se cumplieron los objetivos secundarios, de lo contrario false
    bool objetivosSecundariosCumplidos();

    // Precondiciones:
    // Postcondiciones: devuelve true si el jugador tiene 0 energia, de lo contrario devuelve false
    bool jugadorSinEnergias();

    // Precondiciones:
    // Postcondiciones: devuelve el atributo ordenDeTurno
    int obtenerTurno();

    // Precondiciones:
    // Postcondiciones: devuelve el atributo posicionX
    int obtenerPosicionX();

    // Precondiciones:
    // Postcondiciones: devuelve el atributo posicionY
    int obtenerPosicionY();
};


#endif //TP3_JUGADOR_H
