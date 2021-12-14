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
    Jugador();
    Jugador(int);
    ~Jugador();

    void cargarMaterial(string nombreMaterial, int cantidadMaterial);
    void recibirMatrizDeCostos(int** matrizDeCostos);
    void mostrarMateriales();
    bool suficienteEnergia(int cantidadRequerida);
    void asignarTurno(int numeroDeTurno);
    ListaMateriales* obtenerListaMateriales();
    void asignarNombre(string nombreElegido);
    string obtenerNombreJugador();
    void restarEnergia(int cantidadEnergia);
    void sumarEnergia(int cantidadEnergia);
    int obtenerEnergia();
    bool objetivoPrincipalCumplido();
    bool objetivosSecundariosCumplidos();
    bool jugadorSinEnergias();
    int obtenerTurno();
    int obtenerPosicionX();
    int obtenerPosicionY();
};


#endif //TP3_JUGADOR_H
