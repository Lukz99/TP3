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
    int posicionX, posicionY;
    ListaMateriales* listaMateriales;
    int** matrizDeCostosJugador;
    //Objetivos* objetivosJugador;
    int energia;

    // Metodos
public:
    Jugador();
    Jugador(int);
    ~Jugador();

    void cargarMaterial(string nombreMaterial, int cantidadMaterial);
    void recibirMatrizDeCostos(int** matrizDeCostos);
    void mostrarMateriales();
    bool suficienteEnergia(int cantidadRequerida);
    void asignarTurno(int numeroDeTurno);
    void cargarPosicion(int x, int y);
    int obtenerPosicionX();
    int obtenerPosicionY();
    ListaMateriales* obtenerListaMateriales();
    void asignarNombre(string nombreElegido);
    string obtenerNombreJugador();
    void restarEnergia(int cantidadEnergia);
    void sumarEnergia(int cantidadEnergia);
    int obtenerEnergia();
    int obtenerTurno();
    bool objetivoPrincipalCumplido();
    bool objetivosSecundariosCumplidos();
    bool jugadorSinEnergias();
};


#endif //TP3_JUGADOR_H
