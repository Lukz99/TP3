#ifndef CASILLERO_H
#define CASILLERO_H

class Casillero {
protected:
    char terreno;
    char terrenoInicial;
public:
    Casillero(char );
    virtual ~Casillero();

    virtual void mostrar() = 0;
    virtual char getTerreno() = 0;
    virtual void modificar(char) = 0;
    virtual char getInicial() = 0;
};

#endif //CASILLERO_H
