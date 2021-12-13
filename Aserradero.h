#ifndef TP3_ASERRADERO_H
#define TP3_ASERRADERO_H

#include "Edificio.h"

class Aserradero : public Edificio {
    //Atributos
private:
    string nombreMaterialGenerable = "madera";
    int cantidadMaterialGenerable = 25;
    char nombreClave;


    //Metodos
public:

    // Precondiciones:
    // Postcondiciones:
    Aserradero();
    ~Aserradero() override;

    // Precondiciones:
    // Postcondiciones:
    Aserradero(int piedra, int madera, int metal, int maximoPermitidos);

    string obtenerNombreMaterialGenerable() override;
    int obtenerCantidadMaterialGenerable() override;
    char obtenerNombreClave() override;
    string obtenerPropietario() override;
    void declararPropietario(string nombreJugador) override;
};


#endif //TP3_ASERRADERO_H
