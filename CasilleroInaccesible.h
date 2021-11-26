//
// Created by juamp on 3/11/2021.
//

#ifndef UNTITLED_CASILLEROINACCESIBLE_H
#define UNTITLED_CASILLEROINACCESIBLE_H
#include "Casillero.h"

class CasilleroInaccesible : public Casillero{
private:
    int fila, columna;
public:
    CasilleroInaccesible(char,int,int);
    void mostrar() override;
    void modificar(char) override;
    char getTerreno() override;
    char getInicial() override;
};

#endif //UNTITLED_CASILLEROINACCESIBLE_H
