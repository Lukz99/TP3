#include "Aserradero.h"


Aserradero::Aserradero(string nombre, int piedra, int madera, int metal, int construidos, int produccion) : Edificio(nombre, piedra, madera, metal, construidos) {
    this -> produccion = 25;
}