#ifndef TP3_ESCUELA_H
#define TP3_ESCUELA_H
#include <string>
#include "Edificio.h"

using namespace std;

class Escuela : public Edificio {
    // Atributos
private:
    string nombreMaterialGenerable = "andycoins";
    int cantidadMaterialGenerable = 25;

    // Metodos
public:
    // Constructor sin parametros
    Escuela();

    // Constructor con parametros
    Escuela(int cantidadPiedra, int cantidadMadera, int cantidadMetal, int maximoPermitido);

    ~Escuela() override;

    // Precondiciones:
    // Postcondiciones: devuelve el nombre del material que genera una escuela
    string obtenerNombreMaterialGenerable() override;

    // Precondiciones:
    // Postcondiciones: devuelve la cantidad de material que produce la escuela
    int obtenerCantidadMaterialGenerable() override;

    // Precondiciones:
    // Postcondiciones: devuelve el nombre clave de una escuela
    char obtenerNombreClave() override;

    // Precondiciones:
    // Postcondiciones: define el valor del atributo propietario
    void declararPropietario(string nombreJugador) override;

    // Precondiciones:
    // Postcondiciones: devuelve el atributo propietario
    string obtenerPropietario() override;

};


#endif //TP3_ESCUELA_H
