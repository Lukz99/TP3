#ifndef UNTITLED_CASILLEROCONSTRUIBLE_H
#define UNTITLED_CASILLEROCONSTRUIBLE_H
#include "Casillero.h"
#include "Edificio.h"

class CasilleroConstruible : public Casillero {
private:
    int fila,columna;
    Edificio *edificiacion;

    void setEdificacion();

public:
    CasilleroConstruible(char,int,int);
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
