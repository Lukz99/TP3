#ifndef CASILLEROCONSTRUIBLE_H
#define CASILLEROCONSTRUIBLE_H
#include "Casillero.h"
#include "Edificio.h"

class CasilleroConstruible : public Casillero {
private:
    Edificio *edificiacion;

public:
    CasilleroConstruible(char tipoTerreno);
    ~CasilleroConstruible();

    void mostrar() override;
    char getTerreno() override;
    char getInicial() override;
    void modificar(char) override;

    void construirEdificio(string,Casillero*** casilleros);
    void demolerEdificio(Casillero*** casilleros);

    int getFila();
    int getColumna();
    Edificio* getEdificio();
};


#endif //UNTITLED_CASILLEROCONSTRUIBLE_H
