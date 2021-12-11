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
    int **matrizDeCostosJugador;
    string objetivos[3];
    int energia;
public:
    Jugador();
    Jugador(int);
    ~Jugador();

    string obtenerNombreJugador();
    void cargarMaterial(string nombreMaterial,int cantidadMaterial);
    void recibirMatrizDeCostos(int **matrizDeCostos);
    void mostrarMateriales();
    ListaMateriales* obtenerListaMateriales();
    void restarEnergia(int);
    void sumarEnergia(int);
    int obtenerEnergia();
    bool objetivoPrincipalCumplido();
    bool objetivosSecundariosCumplidos();
};


#endif //TP3_JUGADOR_H
