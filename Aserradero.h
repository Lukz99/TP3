#ifndef TP3_ASERRADERO_H
#define TP3_ASERRADERO_H

#include "edificio.h"

class Aserradero : public Edificio {
    //Atributos
private:

    int produccion;
    string tipoProduccion = "madera";

    //Metodos
public:
    Aserradero(string nombre, int madera, int piedra, int metal, int construidos, int produccion);
};


#endif //TP3_ASERRADERO_H
