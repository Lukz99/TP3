#ifndef TP3_JUGADOR_H
#define TP3_JUGADOR_H
#include <string>
#include "Material.h"
#include "ListaMateriales.h"

using namespace std;

class Jugador {
private:
    string nombreJugador;
    ListaMateriales *listaMateriales;
    string objetivos[3];
    int energia = 50;
public:
    Jugador();
    Jugador(int);
    ~Jugador();

    void cargarMaterial(string nombreMaterial,int cantidadMaterial);
    void mostrarMateriales();
    void restarEnergia(int);
    void restaurarEnergia();
    int obtenerEnergia();
    bool objetivoPrincipalCumplido();
    bool objetivosSecundariosCumplidos();
};


#endif //TP3_JUGADOR_H
