#ifndef TP3_PLANTAELECTRICA_H
#define TP3_PLANTAELECTRICA_H
#include <string>
#include "Edificio.h"

class PlantaElectrica : public Edificio{
private:
    string nombreMaterialGenerable = "energia";
    int cantidadMaterialGenerable = 15;
public:
    PlantaElectrica();
    PlantaElectrica(int,int,int,int);
};


#endif //TP3_PLANTAELECTRICA_H
