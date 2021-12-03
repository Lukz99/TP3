//
// Created by ekizu on 3/12/2021.
//

#ifndef INC_3MOSQUETEROS_NODOPILA_H
#define INC_3MOSQUETEROS_NODOPILA_H
#include "Material.h"

class NodoPila {
private:
    Material *materialJugador;
    NodoPila* siguiente;
public:
    NodoPila(string,int);
    ~NodoPila();
    void insertarNodoSiguiente(NodoPila*);
    Material* obtenerMaterial();
    NodoPila* obtenerNodoSiguiente();
};


#endif //INC_3MOSQUETEROS_NODOPILA_H
