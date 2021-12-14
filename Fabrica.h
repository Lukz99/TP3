#ifndef TP3_FABRICA_H
#define TP3_FABRICA_H

#include "Edificio.h"
#include <string>

using namespace std;

class Fabrica : public Edificio {
    // Atributos
private:
    string nombreMaterialGenerable = "metal";
    int cantidadMaterialGenerable = 40;
    char nombreClave;

    // Metodos
public:
    // Constructor sin parametros
    Fabrica();

    // Constructor con parametros
    Fabrica(int cantidadPiedra, int cantidadMadera, int cantidadMetal, int maximoPermitido);

    ~Fabrica() override;

    // Precondiciones:
    // Postcondiciones: devuelve el nombre del material que genera una fabrica
    string obtenerNombreMaterialGenerable() override;

    // Precondiciones:
    // Postcondiciones: devuelve la cantidad de material que produce una fabrica
    int obtenerCantidadMaterialGenerable() override;

    // Precondiciones:
    // Postcondiciones: devuelve el nombre clave de una fabrica
    char obtenerNombreClave() override;

    // Precondiciones:
    // Postcondiciones: define el valor del atributo propietario
    void declararPropietario(string nombreJugador) override;

    // Precondiciones:
    // Postcondiciones: devuelve el atributo propietario
    string obtenerPropietario() override;
};


#endif //TP3_FABRICA_H
