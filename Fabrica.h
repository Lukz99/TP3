#ifndef TP3_FABRICA_H
#define TP3_FABRICA_H

#include "Edificio.h"
#include <string>

using namespace std;

class Fabrica : public Edificio{
private:
    string nombreMaterialGenerable = "metal";
    int cantidadMaterialGenerable = 40;
    char nombreClave;


public:
    Fabrica();
    Fabrica(int,int,int,int);
    ~Fabrica() override;
    string obtenerNombreMaterialGenerable() override;
    int obtenerCantidadMaterialGenerable() override;
    char obtenerNombreClave() override;
    void declararPropietario(string nombreJugador) override;
    string obtenerPropietario() override;
};


#endif //TP3_FABRICA_H
