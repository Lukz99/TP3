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
    // Constructor sin parametros
    Aserradero();
    ~Aserradero() override;

    // Constructor con parametros
    Aserradero(int piedra, int madera, int metal, int maximoPermitidos);

    // Precondiciones:
    // Postcondiciones: devuelve el material que produce Aserradero
    string obtenerNombreMaterialGenerable() override;

    // Precondiciones:
    // Postcondiciones: devuelve la cantidad de material que produce Aserradero
    int obtenerCantidadMaterialGenerable() override;

    // Precondiciones:
    // Postcondiciones: devuelve el atributo nombreClave
    char obtenerNombreClave() override;

    // Precondiciones:
    // Postcondiciones: devuelve el atributo propietario
    string obtenerPropietario() override;

    // Precondiciones: nombreJugador es valido
    // Postcondiciones: define el valor del atributo propietario
    void declararPropietario(string nombreJugador) override;
};


#endif //TP3_ASERRADERO_H
