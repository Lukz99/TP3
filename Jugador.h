#ifndef TP3_JUGADOR_H
#define TP3_JUGADOR_H
#include <string>
#include "Material.h"
#include "ListaMateriales.h"
#include "Objetivos.h"

using namespace std;

class Jugador {
private:
    string nombreJugador;
    int ordenDeTurno;
    ListaMateriales* listaMateriales;
    int** matrizDeCostosJugador;
    Objetivos* objetivosJugador;
    int energia;
public:
    Jugador();
    Jugador(int);
    ~Jugador();

    string obtenerNombreJugador();
    void cargarMaterial(string nombreMaterial, int cantidadMaterial);
    void recibirMatrizDeCostos(int** matrizDeCostos);
    void mostrarMateriales();
    void asignarTurno(int numeroDeTurno);
    ListaMateriales* obtenerListaMateriales();
    void asignarNombre(string nombreSegunTurno);
    void restarEnergia(int cantidadEnergia);
    void sumarEnergia(int cantidadEnergia);
    int obtenerEnergia();
    bool objetivoPrincipalCumplido();
    bool objetivosSecundariosCumplidos();
    bool jugadorSinEnergias();
};


#endif //TP3_JUGADOR_H
