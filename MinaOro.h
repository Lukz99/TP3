#ifndef TP3_MINAORO_H
#define TP3_MINAORO_H
#include <string>
#include "Edificio.h"

class MinaOro : public Edificio{
private:
    string nombreMaterialGenerable = "andycoins";
    int cantidadMaterialGenerable = 50, estadoEdificio;
    char nombreClave;


public:
    MinaOro();
    MinaOro(int,int,int,int);
    void repararEdificio();
    void destruirEdificio();
    int obtenerEstadoEdificio();
    string obtenerNombreMaterialGenerable() override;
    int obtenerCantidadMaterialGenerable() override;
    char obtenerNombreClave() override;


};

#endif //TP3_MINAORO_H
