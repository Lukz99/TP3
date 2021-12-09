#ifndef UNTITLED_CASILLEROTRANSITABLE_H
#define UNTITLED_CASILLEROTRANSITABLE_H
#include "Casillero.h"
#include "Material.h"

class CasilleroTransitable : public Casillero{
private:
    int fila, columna;
    Material *material;
public:
    CasilleroTransitable(char tipoTerreno);

    ~CasilleroTransitable();

    void setMaterial();

    void mostrar() override;
    void modificar(char ) override;
    char getTerreno() override;
    char getInicial() override;


    void generarMaterial(string,int,Casillero***);
    //void recolectarMaterial(Casillero***);

    int getFila();
    int getColumna();
    Material* getMaterial();
};

#endif //UNTITLED_CASILLEROTRANSITABLE_H
