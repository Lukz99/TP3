#ifndef CASILLEROINACCESIBLE_H
#define CASILLEROINACCESIBLE_H
#include "Casillero.h"

class CasilleroInaccesible : public Casillero {
    // Atributos

    // Metodos
public:

    // Precondiciones:
    // Postcondiciones:
    CasilleroInaccesible(char tipoTerreno);

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
};

#endif //CASILLEROINACCESIBLE_H
