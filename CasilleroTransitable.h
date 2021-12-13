#ifndef CASILLEROTRANSITABLE_H
#define CASILLEROTRANSITABLE_H
#include "Casillero.h"
#include "Material.h"

class CasilleroTransitable : public Casillero {
    // Atributos
private:
    Material *material;

    //Metodos
public:
    // Precondiciones:
    // Postcondiciones:
    CasilleroTransitable(char tipoTerreno);

    // Precondiciones:
    // Postcondiciones:
    ~CasilleroTransitable();

    // Precondiciones:
    // Postcondiciones:
    void mostrar() override;

    // Precondiciones:
    // Postcondiciones:
    void modificar(char) override;

    // Precondiciones:
    // Postcondiciones:
    char obtenerTerreno() override;

    // Precondiciones:
    // Postcondiciones:
    char obtenerInicial() override;

    // Precondiciones:
    // Postcondiciones:
    void generarMaterial(string, int cantidadMaterial, Casillero***, int posicionX, int posicionY);

    // Precondiciones:
    // Postcondiciones:
    void recolectarMaterial(Casillero***);

    // Precondiciones:
    // Postcondiciones:
    int obtenerFila();

    // Precondiciones:
    // Postcondiciones:
    int obtenerColumna();

    // Precondiciones:
    // Postcondiciones:
    Material* obtenerMaterial();

    bool materialPresente();
};

#endif //CASILLEROTRANSITABLE_H
