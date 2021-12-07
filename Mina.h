//
// Created by Lucas on 26/11/2021.
//

#ifndef TP3_MINA_H
#define TP3_MINA_H

#include <string>
#include "Edificio.h"

class Mina : public Edificio {
private:
    string nombreMaterialGenerable = "piedra";
    int cantidadMaterialGenerable = 15;
public:
    Mina(int,int,int,int);
};

#endif //TP3_MINA_H
