//
// Created by juamp on 3/11/2021.
//

#ifndef UNTITLED_CASILLEROCONSTRUIBLE_H
#define UNTITLED_CASILLEROCONSTRUIBLE_H
#include "Casillero.h"
#include "Edificio.h"

class CasilleroConstruible : public Casillero {
private:
    Edificio *edificiacion;

    void setEdificacion();

public:
    CasilleroConstruible(char tipoTerreno);
    ~CasilleroConstruible();

    void mostrar() override;
    char getTerreno() override;
    char getInicial() override;
    void modificar(char) override;

    void construirEdificio(string,int,int,int,int,Casillero*** casilleros);
    void demolerEdificio(Casillero*** casilleros);

    int getFila();
    int getColumna();
    Edificio* getEdificio();
};


#endif //UNTITLED_CASILLEROCONSTRUIBLE_H
