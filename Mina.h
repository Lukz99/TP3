#ifndef TP3_MINA_H
#define TP3_MINA_H

#include <string>
#include "Edificio.h"

class Mina : public Edificio {
private:
    string nombreMaterialGenerable = "piedra";
    int cantidadMaterialGenerable = 15;
    char nombreClave = 'M';

public:
    Mina();
    Mina(int,int,int,int);
    ~Mina() override;
    string obtenerNombreMaterialGenerable() override;
    int obtenerCantidadMaterialGenerable() override;
    char obtenerNombreClave() override;
    void declararPropietario(string nombreJugador) override;
    string obtenerPropietario() override;


};

#endif //TP3_MINA_H
