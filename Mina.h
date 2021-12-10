#ifndef TP3_MINA_H
#define TP3_MINA_H

#include <string>
#include "Edificio.h"

class Mina : public Edificio {
private:
    string nombreMaterialGenerable = "piedra";
    int cantidadMaterialGenerable = 15;
public:
    Mina();
    Mina(int,int,int,int);
};

#endif //TP3_MINA_H
