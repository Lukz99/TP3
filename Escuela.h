#ifndef TP3_ESCUELA_H
#define TP3_ESCUELA_H
#include <string>
#include "Edificio.h"

using namespace std;

class Escuela : public Edificio {
private:
    string nombreMaterialGenerable = "andycoins";
    int cantidadMaterialGenerable = 25;

public:
    Escuela();
    Escuela(int,int,int,int);
    string obtenerNombreMaterialGenerable() override;
    int obtenerCantidadMaterialGenerable() override;
    char obtenerNombreClave() override;

};


#endif //TP3_ESCUELA_H
