#ifndef TP3_ASERRADERO_H
#define TP3_ASERRADERO_H

#include "edificio.h"

class Aserradero : public Edificio {
    //Atributos
private:
    string nombreMaterialGenerable = "madera";
    int cantidadMaterialGenerable = 25;

    //Metodos
public:
    Aserradero(string nombre, int madera, int piedra, int metal, int construidos);
};


#endif //TP3_ASERRADERO_H
