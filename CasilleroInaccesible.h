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
    // Postcondiciones: imprime por pantalla el valor del atributo terreno
    void mostrar() override;

    // Precondiciones:
    // Postcondiciones: modifica el valor del atributo terreno
    void modificar(char terreno) override;

    // Precondiciones:
    // Postcondiciones: devuelve el valor del atributo terreno
    char obtenerTerreno() override;

    // Precondiciones:
    // Postcondiciones: devuelve el valor del atributo terrenoInicial
    char obtenerInicial() override;
};

#endif //CASILLEROINACCESIBLE_H
