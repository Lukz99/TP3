#ifndef CASILLEROINACCESIBLE_H
#define CASILLEROINACCESIBLE_H
#include "Casillero.h"

class CasilleroInaccesible : public Casillero {
public:
    CasilleroInaccesible(char tipoTerreno);
    void mostrar() override;
    void modificar(char) override;
    char getTerreno() override;
    char getInicial() override;
};

#endif //CASILLEROINACCESIBLE_H
