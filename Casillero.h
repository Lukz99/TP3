#ifndef CASILLERO_H
#define CASILLERO_H

class Casillero {
    // Atributos
protected:
    char terreno;
    char terrenoInicial;

    // Metodos
public:
    // Precondiciones:
    // Postcondiciones:
    Casillero(char);

    // Precondiciones:
    // Postcondiciones:
    virtual ~Casillero();

    // Precondiciones:
    // Postcondiciones:
    virtual void mostrar() = 0;

    // Precondiciones:
    // Postcondiciones:
    virtual char obtenerTerreno() = 0;

    // Precondiciones:
    // Postcondiciones:
    virtual void modificar(char) = 0;

    // Precondiciones:
    // Postcondiciones:
    virtual char obtenerInicial() = 0;
};

#endif //CASILLERO_H
