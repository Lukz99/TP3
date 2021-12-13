#ifndef TP3_OBELISCO_H
#define TP3_OBELISCO_H
#include <string>
#include "Edificio.h"

using namespace std;

class Obelisco : public Edificio {
private:
    string nombreMaterialGenerable = "";
    int cantidadMaterialGenerable = 0;
    char nombreClave;


public:
    Obelisco();
    Obelisco(int piedra ,int madera, int metal, int maximoPermitidos);
    ~Obelisco() override;

    string obtenerNombreMaterialGenerable() override;
    int obtenerCantidadMaterialGenerable() override;
    char obtenerNombreClave() override;
    void declararPropietario(string nombreJugador) override;
    string obtenerPropietario() override;


};

#endif //TP3_OBELISCO_H
