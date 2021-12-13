#ifndef CASILLEROCONSTRUIBLE_H
#define CASILLEROCONSTRUIBLE_H
#include "Casillero.h"
#include "Edificio.h"

class CasilleroConstruible : public Casillero {
    // Atributos
private:
    Edificio *edificiacion;

    // Metodos
public:
    // Precondiciones:
    // Postcondiciones:
    CasilleroConstruible(char tipoTerreno);

    // Precondiciones:
    // Postcondiciones:
    ~CasilleroConstruible();

    // Precondiciones:
    // Postcondiciones:
    void mostrar() override;

    // Precondiciones:
    // Postcondiciones:
    char obtenerTerreno() override;

    // Precondiciones:
    // Postcondiciones:
    char obtenerInicial() override;

    // Precondiciones:
    // Postcondiciones:
    void modificar(char) override;

    // Precondiciones:
    // Postcondiciones:
    void construirEdificio(string, Casillero ***casilleros, int coordenadaX, int coordenadaY);

    // Precondiciones:
    // Postcondiciones:
    void demolerEdificio(Casillero ***casilleros);

    // Precondiciones:
    // Postcondiciones:
    int obtenerFila();

    // Precondiciones:
    // Postcondiciones:
    int obtenerColumna();

    // Precondiciones:
    // Postcondiciones:
    Edificio *obtenerEdificio();

    void edificiosReparables(bool repararEdificio, Casillero ***casilleros);
    bool edificioConstruido();

};

#endif //UNTITLED_CASILLEROCONSTRUIBLE_H
