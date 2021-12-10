#ifndef TP3_ASERRADERO_H
#define TP3_ASERRADERO_H

#include "Edificio.h"

class Aserradero : public Edificio {
    //Atributos
private:
    string nombreMaterialGenerable = "madera";
    int cantidadMaterialGenerable = 25;

    //Metodos
public:
    Aserradero();
    Aserradero(int,int,int,int);
};


#endif //TP3_ASERRADERO_H
