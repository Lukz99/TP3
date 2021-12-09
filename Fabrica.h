#ifndef TP3_FABRICA_H
#define TP3_FABRICA_H

#include "Edificio.h"
#include <string>

using namespace std;

class Fabrica : public Edificio{
private:
    string nombreMaterialGenerable = "metal";
    int cantidadMaterialGenerable = 40;
public:
    Fabrica(int,int,int,int);
};


#endif //TP3_FABRICA_H
