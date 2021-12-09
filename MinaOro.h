#ifndef TP3_MINAORO_H
#define TP3_MINAORO_H
#include <string>
#include "Edificio.h"

class MinaOro : public Edificio{
private:
    string nombreMaterialGenerable = "andycoins";
    int cantidadMaterialGenerable = 50;
public:
    MinaOro(int,int,int,int);
};

#endif //TP3_MINAORO_H
