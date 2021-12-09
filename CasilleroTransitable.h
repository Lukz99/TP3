#ifndef CASILLEROTRANSITABLE_H
#define CASILLEROTRANSITABLE_H
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

#endif //CASILLEROTRANSITABLE_H
