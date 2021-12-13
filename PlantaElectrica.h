#ifndef TP3_PLANTAELECTRICA_H
#define TP3_PLANTAELECTRICA_H
#include <string>
#include "Edificio.h"

class PlantaElectrica : public Edificio{
private:
    string nombreMaterialGenerable = "energia";
    int cantidadMaterialGenerable = 15;
    char nombreClave;

public:
    PlantaElectrica();
    PlantaElectrica(int,int,int,int);
    string obtenerNombreMaterialGenerable() override;
    int obtenerCantidadMaterialGenerable() override;
    char obtenerNombreClave() override;

};


#endif //TP3_PLANTAELECTRICA_H
